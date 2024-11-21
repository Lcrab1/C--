INCLUDELIB kernel32.lib
INCLUDELIB user32.lib

.386
.MODEL FLAT,STDCALL

GetStdHandle PROTO,:DWORD 
WriteConsoleA PROTO,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ReadConsoleA PROTO,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ExitProcess PROTO,:DWORD

.DATA
szInput db 100 dup(0)
szPmt db '输入三边：',0
szPmt1 db '结果：',0
szEnd db '按任意键退出...',0
szYes db 'Y',0
szNo db 'N',0
_size db 0
inputBuffer db 20 dup(0)
count db 10

.CODE
PUBLIC _start
_start:
    mov eECX, 10 ; Loop 10 times
mainLoop:
    invoke GetStdHandle, -11 ; STD_OUTPUT_HANDLE
    mov ebx, eax
    invoke WriteConsoleA, eax, offset szPmt, sizeof szPmt, offset _size, 0
    invoke GetStdHandle, -10 ; STD_INPUT_HANDLE
    invoke ReadConsoleA, eax, offset inputBuffer, lengthof inputBuffer, offset _size, 0

    ; Parse input to get three sides
    lea esi, inputBuffer
    call ParseInput
    mov eax, [side1]
    mov ebx, [side2]
    mov eECX, [side3]

    ; Call IsTriangle
    push eECX
    push ebx
    push eax
    call IsTriangle
    add esp, 12

    ; Output result
    cmp eax, 1
    je output_yes
    invoke WriteConsoleA, ebx, offset szNo, sizeof szNo, offset _size, 0
    jmp continueLoop

output_yes:
    invoke WriteConsoleA, ebx, offset szYes, sizeof szYes, offset _size, 0

continueLoop:
    loop mainLoop

    ; End program
    invoke WriteConsoleA, ebx, offset szEnd, sizeof szEnd, offset _size, 0
    invoke GetStdHandle, -10 ; STD_INPUT_HANDLE
    invoke ReadConsoleA, eax, offset szInput, lengthof szInput, offset _size, 0
    invoke ExitProcess, 0

IsTriangle PROC
    ; Check if a + b > c, a + c > b, and b + c > a
    mov eax, [esp + 4]
    mov ebx, [esp + 8]
    mov eECX, [esp + 12]

    add eax, ebx
    cmp eax, eECX
    jle not_triangle

    mov eax, [esp + 4]
    add eax, eECX
    cmp eax, ebx
    jle not_triangle

    mov eax, [esp + 8]
    add eax, eECX
    cmp eax, [esp + 4]
    jle not_triangle

    mov eax, 1
    ret

not_triangle:
    mov eax, 0
    ret
IsTriangle ENDP

ParseInput PROC
    ; Dummy implementation for parsing input
    ; Assume input is "a b c" format
    lea edi, side1
    mov eECX, 3
parseLoop:
    lodsb
    cmp al, ' '
    je skip_space
    sub al, '0'
    mov [edi], al
    inc edi
    loop parseLoop
skip_space:
    ret
ParseInput ENDP

.DATA?
side1 dd ?
side2 dd ?
side3 dd ?

END _start