asm(
        "push ds"
        "pop es"
        "mov esi, offset input_str"
        "mov edi, offset output_str"
        "operation:"
            "lodsb"
            "cmp al, 32"
            "jne first"
            "stosb"
            "jne final"

            "first: ;numbers check"
                "cmp al, 48"
                "jb final"
                "cmp al, 47"
                "ja second"
                "stosb"
                "jmp final"

            "second: ;1st pool of russian letters"
                "cmp al, 128"
                "jb final"
                "cmp al, 175"
                "ja third"
                "stosb"
                "jmp final"

            "third: ;2nd pool of russian letters"
                "cmp al, 224"
                "jb final"
                "cmp al, 241"
                "ja final"
                "stosb"
                "jmp final"
            "final:"
        "mov ecx, '\0'"
                "cmp ecx, [esi]"
                "je exit"
        "jmp operarion"
            "exit:"
    );