#include <stdio.h>
#include <wchar.h>
#include <locale.h>
#include <windows.h>

#define N 80

wchar_t input_str[N];
wchar_t output_str[N];

int main(){
    
    setlocale(LC_ALL, "");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    wprintf(L"\tВариант 1. Хомутинников Никита, студент гр.1381");
    wprintf(L"\n\tЗадача - формирование выходной строки только из цифр и русских букв входной строки\n");

    fgetws(input_str, N, stdin);
    input_str[wcslen(input_str-1)] = '\0';
    __asm(
        "\t push ds \n"
        "\t pop es \n"
        "\t mov esi, offset input_str \n" ; Здесь выдает ошибку
        "\t mov edi, offset output_str \n" ; И здесь тоже
        "\t operation: \n"
        "\t lodsb \n"
            "\t cmp %al, 32 \n"
            "\t jne first \n"
            "\t stosb \n"
            "\t jne final \n"

            "\t first: \n"
            "\t cmp %al, 48 \n"
            "\t jb final \n"
            "\t cmp %al, 47 \n"
            "\t ja second \n"
            "\t stosb \n"
           "\t jmp final \n"

            "\t second: \n"
            "\t cmp %al, 128 \n"
            "\t jb final \n"
            "\t cmp %al, 175 \n"
            "\t ja third \n"
            "\t stosb \n"
            "\t jmp final \n"

            "\t third: \n"
            "\t cmp %al, 224 \n"
            "\t jb final \n"
            "\t cmp %al, 241 \n"
            "\t ja final \n"
            "\t stosb \n"
            "\t jmp final \n"
            "\t final: \n"
        "\t mov %ecx, '\0' \n"
            "\t cmp %ecx, [esi] \n"
            "\t je exit \n"
        "\t jmp operarion \n"
            "\t exit: \n"
    );

	wprintf(L"Итоговая строка: %ls", output_str);

}
