#include <stdio.h>
#include <string.h>

/* MIT License

Copyright (c) 2021-2023 Linus Dierheimer
Copyright (c) 2022-2025 Carter Li

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.*/

// the ascii art in this file is from FastFetch:
// https://github.com/fastfetch-cli/fastfetch
// all credits go to the fastfetch team, as they put in the time and effort to create these logos.

void ascii(const char *str) {
if (strcmp(str, "Linux Mint") == 0) {
    printf(
        "\e[1;32m"
        "\n\t\t\t             ...-:::::-..."
        "\n\t\t\t          .-MMMMMMMMMMMMMMM-."
        "\n\t\t\t      .-MMMM`..-:::::::-..`MMMM-."
        "\n\t\t\t    .:MMMM.:MMMMMMMMMMMMMMM:.MMMM:."
        "\n\t\t\t   -MMM-M---MMMMMMMMMMMMMMMMMMM.MMM-"
        "\n\t\t\t `:MMM:MM`  :MMMM:....::-...-MMMM:MMM:`"
        "\n\t\t\t :MMM:MMM`  :MM:`  ``    ``  `:MMM:MMM:"
        "\n\t\t\t.MMM.MMMM`  :MM.  -MM.  .MM-  `MMMM.MMM."
        "\n\t\t\t:MMM:MMMM`  :MM.  -MM-  .MM:  `MMMM-MMM:"
        "\n\t\t\t:MMM:MMMM`  :MM.  -MM-  .MM:  `MMMM:MMM:"
        "\n\t\t\t:MMM:MMMM`  :MM.  -MM-  .MM:  `MMMM-MMM:"
        "\n\t\t\t.MMM.MMMM`  :MM:--:MM:--:MM:  `MMMM.MMM."
        "\n\t\t\t :MMM:MMM-  `-MMMMMMMMMMMM-`  -MMM-MMM:"
        "\n\t\t\t  :MMM:MMM:`                `:MMM:MMM:"
        "\n\t\t\t   .MMM.MMMM:--------------:MMMM.MMM."
        "\n\t\t\t     '-MMMM.-MMMMMMMMMMMMMMM-.MMMM-'"
        "\n\t\t\t       '.-MMMM``--:::::--``MMMM-.'"
        "\n\t\t\t            '-MMMMMMMMMMMMM-'"
        "\n\t\t\t               ``-:::::-``"
        "\n\e[0;37m"
    );
}

if (strcmp(str, "Arch Linux") == 0) {
    printf("\e[1;34m"
           "\n\t\t\t                  -`"
           "\n\t\t\t                 .o+`"
           "\n\t\t\t                `ooo/"
           "\n\t\t\t               `+oooo:"
           "\n\t\t\t              `+oooooo:"
           "\n\t\t\t              -+oooooo+:"
           "\n\t\t\t            `/:-:++oooo+:"
           "\n\t\t\t           `/++++/+++++++:"
           "\n\t\t\t          `/++++++++++++++:"
           "\n\t\t\t         `/+++o$2oooooooo$1oooo/`"
           "\n\t\t\t        ./ $2ooosssso++osssssso$1+`"
           "\n\t\t\t       ./ $2.oossssso-````/ossssss+`"
           "\n\t\t\t      -osssssso.      :ssssssso."
           "\n\t\t\t     :osssssss/        osssso+++."
           "\n\t\t\t    /ossssssss/        +ssssooo/-"
           "\n\t\t\t  `/ossssso+/:-        -:/+osssso+-"
           "\n\t\t\t `+sso+:-`                 `.-/+oso:"
           "\n\t\t\t`++:.                           `-/+/"
           "\n\t\t\t.`                                 `/"
           "\n\e[0;37m");
}
}