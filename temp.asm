        "rewrite: \n"
        "lodsb \n"
        "cmp %%rax, 32 \n"
        "je first \n"
        "stosb \n"
        "jmp final \n"

        "first: \n"
        "cmp %%rax, 48 \n"
        "jb final \n"
        "cmp %%rax, 57 \n"
        "ja second \n"
        "stosb \n"
        "jmp final \n"

        "second: \n"
        "cmp %%rax, 128 \n"
        "jb final \n"
        "cmp %%rax, 173 \n"
        "ja third \n"
        "stosb \n"
        "jmp final \n"

        "third: \n"
        "cmp %%rax, 224 \n"
        "jb final \n"
        "cmp %%rax, 241 \n"
        "ja final \n"
        "stosb \n"
        "jmp final \n"

        "final: \n"
        "mov [%[res] + %[idx]*4], rax \n"
        "inc %[idx] \n"
        "loop rewrite \n"

        : [res] "=mr" (output_str)
        : [src] "S" (input_str), [idx] "rb" (0L), [size] "c" (size)
