Postopek inicializacije periferije: b) V Pinout % Configuraton pogledu glede na vašo razvojno ploščico ugotovite, ali lahko uporabite modro tipko za digitalni vhod kot interrupt (GPIO_EXT…). Če da, kateri pin je to?     A0 (GPIO EXIT0)   c) Zapišite naslov izhodnih pinov za zeleno in modro LED:    ZELENA LED: LD3 (PC9) in MODRA LED: LD4 (PC8)__  

Programiranje v IDE: c) Znotraj te funkcije zapišite ukaz za vklop/izklop zelene LED (pomagajte si z metodo toggle, glej vaja0a).      HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_9).       d) Znotraj iste funkcije dodajte še zakasnitev, ki je potrebna, ko uporabimo mehanska tipkala/stikala:                                  for(uint32_t i=0; i<10000; i++);            Koliko znaša (v mili sekundah) zapisana zakasnitev, ki jo proizvede zanka for?                                                          ___2,8125 ms ___.                          e) V user code begin 3 - zanka while(1) - zapišite ukaz za utripanje modre LED (metoda toggle, glej vaja0a):                               HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_8). f) V to zanko dodajte ukaz za zakasnitev z funkcijo Delay iz knjižnice HAL, in sicer pol sekunde (glej vaja0a):                          HAL_Delay(500).

Komentar: Program deluje kot bi moral in nima nobenih napak. 
