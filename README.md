# robot
### Автономный робот теле-присутствия как часть умного дома


![v1](https://raw.githubusercontent.com/positron48/robot/master/images/IMGP2291.JPG "v1")

#### Имеющаяся техническая часть:
* гусеничная платформа rover
* УЗ-дальномеры
* [драйвер двигателя](http://www.aliexpress.com/item/Free-shipping-1pcs-lot-Special-promotions-2pcs-lot-L298N-motor-driver-board-module-stepper-motor-smart/1872427142.html)
* avr (на первом этапе и крайний случай arduino uno)
* rf/nrf модули для связи с пультом управления (для первого этапа отладки)
* [Bluetooth модуль HC-06](http://www.aliexpress.com/item/HC-06-HC06-LI-06-BT-BOARD-4pin-Bluetooth-serial-pass-through-wireless-serial-communication-module/1004377223.html)
* роутер [TP-Link MR3020](http://robocraft.ru/blog/electronics/1053.html)

#### Пока отсутствует:
* 2 энкодера (предположительно будут использованы щелевые энкодеры из мышей как самые доступные)
* [9-осевой датчик](http://www.aliexpress.com/item/MPU-9250-GY-9250-9-axis-sensor-module-I2C-SPI-Communications-Thriaxis-gyroscope-triaxial-accelerometer-triaxial/1885410798.html)
* вебкамера
* 2 сервомотора для поворота камеры
* [лазерный дальномер](http://roboforum.ru/forum10/topic12095.html)

#### Планируемый функционал:
* наличие базовой станции для подзарядки
* ориентирование в пространстве
* полноценное телеприсутствие через web/android-приложение
* возможность самостоятельно следовать в указанную точку на карте помещения ([move_base](http://wiki.ros.org/move_base))
* реализация [SLAM](http://www.robocraft.ru/blog/technology/724.html) (использование готовых библиотек под [ROS](http://robocraft.ru/blog/robosoft/742.html))
* возможность отсылки фотографий
