# 🐼 ToneShell APT Variant (Educational)
```bash
   .--.              .--.
 : (\ ". _......_ ." /) :
  '.    `        `    .'
   /'   _        _   `\
  /     0}      {0     \
 |       /      \       |
 |     /'        `\     |
  \   | .  .==.  . |   /
   '._ \.' \__/ './ _.'
   /  ``'._-''-_.'``  \
```
**`ToneShell // Operation: Panda Trigger`**  
*A covert activation framework with claws 🐾*


> 🎧 A cyberpunk-inspired, tone-triggered, multi-stage in-memory shellcode framework built for research and education only.

ToneShell simulates a covert, modular APT-style loader that activates only when triggered by a specific audio tone. It demonstrates:
- 🎵 Tone-based covert triggers
- 🧠 In-memory payload execution
- 🕵️ AMSI bypass tactics
- 🛰️ XOR-based beaconing
- 🚫 Zero disk touch (LOTL-style)

This is **not malware**. It contains no malicious payloads. All components are either stubbed or simulated and serve an educational purpose.

---

## 📂 Project Structure


---

## 🚀 How It Works

1. **AMSI Patch** – disables Windows Defender AMSI scan in current process.
2. **Audio Trigger** – waits for a simulated secret tone to activate.
3. **Stage2 Loader** – loads and executes dummy shellcode in memory.
4. **Beaconing** – sends an XOR-obfuscated beacon string to simulate C2 contact.

> In a real-world APT, stages could be dropped by phishing, hijacked DLLs, or living-off-the-land (LOTL) techniques.  
> ToneShell showcases that structure—without real weaponization.

---

## 🧠 Learning Objectives

- Understand staged execution and in-memory payload delivery.
- Explore OPSEC-friendly trigger methods (e.g. non-network based).
- Study anti-analysis basics like AMSI bypass.
- Simulate C2 comms obfuscation using simple XOR logic.
- Practice low-level and WinAPI-based loader development.

---

## ⚙️ Build Instructions

```bash
# Windows x64 using MSVC or MinGW-w64
git clone https://github.com/youruser/ToneShell.git
cd ToneShell

# Compile all components (simplified)
gcc main.c Stage2_Loader.c TriggerEngine/audio.c Comms/c2_xor.c Payloads/dummy_payload.c -o toneshell.exe

=== ToneShell APT Variant Demo ===
[Evasion] AMSI patched in memory (AmsiScanBuffer disabled).
[Trigger] Waiting for audio trigger...
[Trigger] **Tone pattern detected** (simulated)
[Stage2] Shellcode is now executing...
[Comms] Sending beacon message 'ACTIVE' (XOR encrypted)...
[Comms] XOR encrypted beacon data: 1B3F2C2F (hex)
=== ToneShell demo completed ===

⚠️ Disclaimer
This project is for educational, academic, and ethical research purposes only.
Do not use this code for malicious or unauthorized activity.
The author disclaims any responsibility for misuse.

✨ Credits
🎧 Audio trigger logic inspired by side-channel covert channels

🧵 Shellcode loader logic modeled after classical malware stagers

🛡️ AMSI bypass adapted from public Red Teaming knowledge

🧠 Designed by SZStack//Rali0s

⚠️ Disclaimer
This project is for educational, academic, and ethical research purposes only.
Do not use this code for malicious or unauthorized activity.
The author disclaims any responsibility for misuse.

✨ Credits
🎧 Audio trigger logic inspired by side-channel covert channels

🧵 Shellcode loader logic modeled after classical malware stagers

🛡️ AMSI bypass adapted from public Red Teaming knowledge

🧠 Designed by Your Name or Handle