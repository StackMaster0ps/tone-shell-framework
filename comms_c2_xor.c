/**
 * Comms/c2_xor.c - XOR-Obfuscated C2 Communications
 * Description: Simulates a beacon to a command-and-control server, with XOR "encryption" to hide the content.
 *              In a real scenario, this would send network requests; here we just print the obfuscated data.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static const unsigned char XOR_KEY = 0x5A;  // Simple XOR key for obfuscation

void Beacon_XOR_Send(const char *data, size_t len) {
    // Allocate buffer for encrypted data
    unsigned char *encrypted = (unsigned char*) malloc(len);
    if (!encrypted) return;
    
    // XOR encrypt the data in-place
    for (size_t i = 0; i < len; ++i) {
        encrypted[i] = data[i] ^ XOR_KEY;
    }
    
    // In a real scenario, the encrypted beacon would be sent over the network (e.g., via sockets) to a C2 server.
    // For this demo, we'll output the encrypted bytes to demonstrate the result of the obfuscation.
    printf("[Comms] XOR encrypted beacon data: ");
    for (size_t i = 0; i < len; ++i) {
        printf("%02X", encrypted[i]);  // print each byte in hex format
    }
    printf(" (hex)\\n");
    
    // Clean up
    free(encrypted);
}
