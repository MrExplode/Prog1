# FLTK build

Ha úgy gondolod hogy mégis saját magadnak szeretnéd az FLTK-t

### Lépések

- Telepítsd a [CMaket](https://cmake.org/download/)
- Telepítsd a [Visual Studiot](https://visualstudio.microsoft.com/vs/)
- Töltsd le az FLTK [forráskódot](https://www.fltk.org/software.php)
- Generáld le cmake gui segítségével a VS projektet  
  ![path configuration](https://cdn.sunstorm.rocks/img/1h0rnt1.png/1crjal1)  
  ![hit configure](https://cdn.sunstorm.rocks/img/48ulii.png/kucn8a)  
  ![finish configure](https://cdn.sunstorm.rocks/img/1g2dqu5.png/1se5i5c)  
  ![hit generate](https://cdn.sunstorm.rocks/img/1tp9dn3.png/2ehgff)
- Nyisd meg Visual Studioban a **build/FLTK.sln** fájlt
- Válts át **Release** módba **Debug**ról  
  ![change to release](https://cdn.sunstorm.rocks/img/17vvujp.png/12g4i2n)
- Buildeld a solutiont  
  ![build solution](https://cdn.sunstorm.rocks/img/tdls6s.png/1pjf89i)

- A kész lib fájlokat megtalálod a **build/lib/release** mappában.
- A header fájlokat megtalálod az **FL** mappában.
