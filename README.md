
# Otel Yönetim Sistemi (Hotel Management System)

Bu proje, bir otel yönetim sistemini C++ ile simüle eden bir uygulamadır. Müşteri ve çalışan işlemleri menüleri aracılığıyla odaların yönetimi, rezervasyon işlemleri ve müşteri sayısının takibi yapılabilir.

## Özellikler

- Müşteri işlemleri:
  - Rezervasyon yapma
  - Rezervasyon iptali
  - Tüm odaları listeleme
- Çalışan işlemleri:
  - Oda ekleme
  - Oda silme
  - Oteldeki toplam müşteri sayısını görüntüleme
- Oda bilgileri yönetimi:
  - Oda numarası, fiyat, oda tipi (Tek kişilik, Çift kişilik, Suit)
  - Rezarvasyon durumu (Boş/Dolu)
  - Kat bilgisi (1, 2, 3)

## Kullanılan Teknolojiler

- C++ (Standart Kütüphaneler: `<iostream>`, `<vector>`, `<memory>`, `<string>`)
- Nesne yönelimli programlama (OOP)
- `shared_ptr` ile bellek yönetimi

## Dosya Yapısı

- `main.cpp` → Programın giriş noktası
- `Hotel.h` & `Hotel.cpp` → Otel sınıfı, menüler, müşteri ve çalışan işlemleri
- `Room.h` → Oda sınıfları (`Floor1`, `Floor2`, `Floor3`) ve enumlar (`Type`, `RezervasyonDurumu`)

## Kurulum

1. Projeyi bilgisayarınıza indirin veya klonlayın:
   ```bash
   git clone <repo-url>
   ```
2. C++ derleyicinizin yüklü olduğundan emin olun (örn. g++, clang++).
3. Terminal veya IDE üzerinden derleyip çalıştırın:
   ```bash
   g++ main.cpp Hotel.cpp -o HotelManagement
   ./HotelManagement
   ```

## Kullanım

1. Program açıldığında ana menü ile karşılaşacaksınız:
   - 1 → Müşteri İşlemleri
   - 2 → Çalışan İşlemleri
   - 3 → Çıkış
2. Müşteri veya çalışan menülerine girdikten sonra ilgili işlemleri gerçekleştirebilirsiniz.
3. Rezervasyon yaparken veya oda eklerken, kullanıcıdan gerekli bilgiler alınır ve sisteme işlenir.
4. Çıkış yapmak için menülerde belirtilen seçenekleri kullanabilirsiniz.

## Katkıda Bulunma

Projeye katkıda bulunmak için:
1. Fork yapın
2. Değişiklikleri branch üzerinde gerçekleştirin
3. Pull request gönderin

## Lisans

Bu proje MIT Lisansı ile lisanslanmıştır.
