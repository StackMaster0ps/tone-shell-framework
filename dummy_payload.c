/**
 * Payloads/dummy_payload.c - Dummy Payload Shellcode (Placeholder)
 * Description: Represents the shellcode/implant to be deployed. Here it's just a few harmless bytes.
 *              In a real case, this could be raw machine code or an embedded DLL to reflectively load.
 */
#include <stddef.h>

unsigned char payload[] = {
    0x90, 0x90, 0xC3   // NOP, NOP, RET: do nothing and return immediately
};
size_t payload_len = sizeof(payload);
