# MSYS2 telepítése

- Töltsd le a telepítőt: [msys2-x86_64-20220128.exe](https://github.com/msys2/msys2-installer/releases/download/2022-01-28/msys2-x86_64-20220128.exe)
- Menj rajta végig, és a végén hagyd bepipálva a _Run MSYS2 64bit now_ opciót.
- A megnyílt shellben futtasd a következő parancsot a package db frissítéséhez:
  Minden promptra írj y-t.

```
pacman -Syu
```

- Nyisd meg a Start menüből a `MSYS2 MSYS`-t
- Futtasd a többi package frissítéséhez a következő parancsot:
  Minden promptra írj y-t.

```
pacman -Su
```

- A `gcc` telepítéséhez futtasd a következő parancsot:

```
pacman -S --needed base-devel mingw-w64-x86_64-toolchain
```

Amikor feldob egy kérdést, csak nyomj entert.

## Path beállítása

Az előző lépésekkel sikeresen telepítetted az MSYS2-t, és a mingw64 gcc compilert. Ugyanakkor a `g++` parancsot jelenleg csak a start menüből, az `MSYS2 MINGW x64` shellből tudod futtatni. Ha ez nem zavar, akkor ne is olvass tovább. Ahhoz hogy az átlagos parancssorunkból is lehessen használni, hozzá kell adni a **Path** nevű környezeti változóhoz.

- Nyisd meg a Start menüt
- Keress a következőre: Környezeti változó (angol windows esetén Environment variable)  
  ![search for env variable](https://cdn.sunstorm.rocks/img/avat10.png/nmm9vm)
- Kattints a környezeti változók gombra  
  ![open environment variables](https://cdn.sunstorm.rocks/img/6racdl.png/1a94be3)
- A rendszer változók között keresd meg a **Path** változót és kattints a **Szerkesztés** gombra  
  ![edit path](https://cdn.sunstorm.rocks/img/k6g3jq.png/69foak)
- Kattints az Új gombra, és írd be a következőt: `C:\msys64\mingw64\bin`  
  ![add new value to path](https://cdn.sunstorm.rocks/img/3hml6b.png/1oddrt8)
- Okézd le mind a három ablakot
- Kész
