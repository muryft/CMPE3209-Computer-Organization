# CMPE3209-Computer-Organization
Yağmur Feyza Tunçer 5001230029

RISC-V RV32IM için C programı: LCG ile 28 not üretir, ortalama hesaplar, notları sınıflandırır.

## Dosyalar
- `code.c`: kaynak kod
- `start.S`: giriş kodu (`_start`, `main`'i çağırır, `ecall` ile biter)
- `link.ld`: linker script (.text 0x0, veri 0x10000000)
- `prog.elf`: derlenmiş çıktı

## Araçlar
- Homebrew LLVM/Clang 23.1.4 (macOS, Apple M1)
- Ripes (sürüm: ?), işlemci: RV32IM (model: ?)

## Derleme
```bash
/opt/homebrew/opt/llvm/bin/clang --target=riscv32 -march=rv32im -mabi=ilp32 \
  -mno-relax -O0 -nostdlib -fuse-ld=lld -Wl,--image-base=0 -Wl,-T,link.ld \
  start.S code.c -o prog.elf
```

## Ripes'te çalıştırma
1. Ripes'te RV32IM destekli bir işlemci seç (M uzantısı işaretli).
2. File → Load program → Input type: **Executable code (ELF)** → `prog.elf`.
3. Run ile programı sonuna kadar çalıştır.
4. Memory sekmesinde **Go to address** ile adreslere bak (gösterim: Decimal).

## Bellek adresleri
| Değişken | Adres |
|---|---|
| bucket[0..4] | 0x10000004 |
| mean | 0x10000018 |
| below_count | 0x1000001c |
| pass_count | 0x10000020 |
| grades[0..27] | 0x10000024 |

Not: Ortalamanın altındaki notlarda `grades[i]` değerine 0x100 (256) eklenir; gerçek not için alt 8 bit (`& 0xFF`) alınmalıdır.
