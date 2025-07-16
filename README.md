# QTrainer Model Uçak Gerçeklemesi

Bu proje, donanım, kablosuz iletişim ve gömülü yazılım bilgilerini uygulamak amacıyla geliştirilmiş bir QTrainer model uçak prototipinin detaylarını sunmaktadır.

## Proje Hakkında

Bu çalışmada, Arduino Nano ve nRF24L01 modülleri kullanılarak 2.4 GHz frekans bandında çalışan, SPI iletişim protokolüne dayalı bir kablosuz kontrol sistemi geliştirilmiştir. Sistem, 4 adet servo motoru ve bir fırçasız motoru (ESC aracılığıyla) gerçek zamanlı olarak PWM sinyalleri ile kontrol edebilmektedir. nRF24L01 modülünün Enhanced ShockBurst protokolü sayesinde güvenilir ve değişken uzunlukta paket veri iletimi sağlanmıştır. RF devresindeki gürültüyü azaltmak ve menzili iyileştirmek için güç hattına 10 µF'lik bir filtre kapasitörü entegre edilmiştir. Gerçekleştirilen uçuş testleri, sistemin stabil bir kontrol deneyimi sunduğunu göstermiştir.

## Temel Özellikler

  * **Kablosuz Kontrol:** 2.4 GHz frekans bandında nRF24L01 modülleri ile güvenilir kablosuz iletişim.
  * **SPI İletişim Protokolü:** Arduino Nano ile nRF24L01 modülleri arasında hızlı ve verimli veri alışverişi.
  * **PWM Kontrolü:** Servo motorlar ve fırçasız motor için hassas hız ve pozisyon kontrolü.
  * **Gürültü Azaltma:** RF devresinde sinyal bütünlüğünü artırmak için filtreleme uygulaması.
  * **Gömülü Yazılım:** Arduino platformunda geliştirilen kontrol algoritmaları.

## Kullanılan Teknolojiler

  * **Donanım:**
      * Arduino Nano
      * nRF24L01 Kablosuz Modüller
      * Servo Motorlar
      * Fırçasız Motor (Brushless Motor)
      * Elektronik Hız Kontrol Cihazı (ESC)
      * 10 µF Filtre Kapasitörü
      * QTrainer Model Uçak Gövdesi
  * **Yazılım & Protokoller:**
      * Arduino IDE (C/C++)
      * SPI İletişim Protokolü
      * Enhanced ShockBurst Protokolü
      * PWM (Pulse Width Modulation)

## Proje Yapısı

```
.
├── QTrainer Model Uçak Prototipinin Gerçeklestirilmesi.pdf # Bitirme Çalışması Raporu
├── README.md                                               # Bu README dosyası
└── alici/                                                  # Proje kodlarını içeren ana klasör (varsayım)
    ├── src/main.cpp                                        # Alıcı Arduino kodu
└── verici/
    ├── src/main.cpp                                        # Verici Arduino kodu
```
## Görseller
![QTrainer Uçak](https://github.com/oalikorkmaz/rcucak/assets/53351567/dd881b69-90f0-4f28-9f0e-1e6b48aaf1df)

## Detaylı Bilgi

  * **Medium Yazısı:** [QTrainer RC Uçak Modellemesi](https://onuralikorkmaz.medium.com/qtrainer-rc-uçak-modellemesi-480bbe9ec36)
  * **Bitirme Çalışması Raporu:** [QTrainer Model Uçak Prototipinin Gerçeklestirilmesi.pdf](https://github.com/oalikorkmaz/rcucak/blob/main/QTrainer%20Model%20U%C3%A7ak%20Prototipinin%20Ger%C3%A7eklestirilmesi.pdf)
  * **Youtube Videosu:** [Proje Demosu](https://youtu.be/Ga4y0oPVHHE)
