<div align="center">
  <img src="https://img.shields.io/badge/Status-Research_Prototype-orange?style=for-the-badge" />
  <img src="https://img.shields.io/badge/License-Proprietary_Core-red?style=for-the-badge" />
  <img src="https://img.shields.io/badge/C++-WinAPI_&_Syscalls-00599C?style=for-the-badge" />
</div>

---

## ⚠️ Project Status: Public Proof of Concept

> **Note:** This repository contains the **open-source kernel** of the project. The full commercial version (including the advanced GUI framework, driver-level optimization, and automated cloud sync) is currently under **private development** and is not available here.

This repo serves as a technical demonstration of how to manipulate OS resources (Memory, CPU, Network) using C++.

---

## 🎯 The Mission

I challenged myself to build the underlying architecture of a system optimizer (similar to CCleaner or Task Manager) from scratch. The goal was to understand **how the OS works**, not just to use it.

<p align="center">
  <img width="100%" alt="System Tools Dashboard" src="https://github.com/user-attachments/assets/3b309eae-a51e-471f-aa41-7a904ff179a4" />
</p>

---

## 🛠️ Public Modules (The "Free" Tier)

These are the core algorithms exposed in this public demo:

### 🧠 Memory & CPU (Kernel Level)
- **RAM Garbage Collector:** Uses `EmptyWorkingSet` (Windows) to force the OS to trim process memory.
- **Thread Prioritizer:** Manually adjusts thread priority classes to boost foreground apps.
- **Process Walker:** Iterates through the snapshot of system processes to identify resource hogs.

### 💾 Disk & Filesystem
- **Byte Scanner:** A fast recursive algorithm to detect duplicate files by comparing byte signatures.
- **Junk Remover:** Safely identifies temporary artifacts in `%TEMP%` and `/var/tmp`.

### 🌐 Network Sockets
- **Port Listener:** Scans local TCP/UDP ports to detect potential vulnerabilities.
- **Latency Tester:** Measures RTT (Round Trip Time) using raw sockets.

---

## 💻 Tech Stack & Architecture

This is not a script; it is a **Systems Application**.

| Component | Technology | Why? |
| :--- | :--- | :--- |
| **Language** | C++17 / C++20 | Zero-overhead abstractions and direct hardware access. |
| **Windows** | Win32 API | Used for `CreateToolhelp32Snapshot`, `VirtualFree`, and Registry access. |
| **Linux** | Syscalls | Direct interaction with `/proc` filesystem and kernel signals. |
| **Build System** | CMake / Makefile | Cross-platform compilation orchestration. |

---

## 🚀 How to Run the Demo

### Windows (Pre-compiled Binary)

<img width="1349" height="893" alt="image" src="https://github.com/user-attachments/assets/2a2ee939-79dd-4619-a52f-20793ee60e28" />
