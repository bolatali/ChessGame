# ChessGame
## Oyunun Derleme Kılavuzu
- Oyun board1.tx, board2.txt veya board3.txt adlı dosyalardan okuma yaparak 8x8'lik bir satranç tahtası oluşturur.
- Bu okuma işlemini setPiecesProperty fonksiyonunda yapar ayrıca bu fonksiyon taşların okunmasından sonra kendine ait nesnelerinin oluşturulduğu bir fonksiyondur.
- setPiecesProperty fonksiyonundaki  readFile.open("") fonksiyonun içine bu 3 tane txt dosyasının adını vererek okuma sağlanabilir.
- startGame fonksiyonu ile oyun başlar ve taşların puan hesaplaması tamamlanır.
- calculateScore fonksiyonu puan hesaplaması yapar fakat argüman olarak taş rengi girilmelidir. Girilen renge göre bir puan hesaplaması yapar.
- Program derlendikten sonra sonuçlar konsol ekranında görülmektedir.
  
## Oyuna Dair Notlar
- Programda piyon, at ve kale taşlarının hareketleri ve özellikleri yer almaktadır. Vaktim yettiğince bu taşların hareketini yazabildiğim için sadece bu taşlara ait sınıf ve fonksiyonlar bulunmaktadır.
- Program tüm taşları okuyup puanlarını belirliyor fakat taşların tehdit edip puan eksiltme işlemini sadece bu üç taşa göre yapmakta.
- Bir taşın birden fazla taş tarafından tehdit edilmesi durumunda puanı aynı sayı doğrultusunda birden fazla kez yarıya indirilmiştir.(Bu kısım dökümanda belirtilmemişti kendim ekledim)
-  Örneğin at 2 taş tarafından tehdit ediliyorsa puanı 3/2 = 1.5    1.5/2 = 0.75 olarak hesaplanmaktadır.




