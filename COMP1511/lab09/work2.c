if (a > 0) {
                if (sightings[i].species[a] >= 65 && sightings[i].species[a] <= 90) {
                    sightings[i].species[a] = sightings[i].species[a] + 32;
                }
                if (check_range(sightings[i].species[a], sightings[i].species[a + 1]) == 0) {
                    int x = 0;
                    while (sightings[i].species[x] != '\0') {
                        sightings[i].species[x] = sightings[i].species[x + 1];
                        x++;
                }
                checka = 1;
                }
            }
            
            if (checka == 1) {
                a--;
            }
            a++;
        }
        i++;printf("\n");
    }
    
