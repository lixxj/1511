printf("%c", sightings[1].species[0]);
    int i = 0;
    while (i < n_sightings) {
    // change sightings[i].species
        int a = 0;
        while (sightings[i].species[a] != '\0') {
            // Capitalise
            printf("%c", sightings[i].species[a]);
            int checka = 0;
            if (a == 0) {
                if (sightings[i].species[a] >= 97 && sightings[i].species[a] <= 122) {
                    sightings[i].species[a] = sightings[i].species[a] - 32;
                }
                if (sightings[i].species[a] == 32) {
                    int x = 0;
                    while (sightings[i].species[x] != '\0') {
                        sightings[i].species[x] = sightings[i].species[x + 1];
                        x++;
                    }
                    checka = 1;
                }
            }
            // to Lowercase
            if (a > 0) {
                if (sightings[i].species[a] >= 65 && sightings[i].species[a] <= 90 && sightings[i].species[a - 1] != 45) {
                sightings[i].species[a] = sightings[i].species[a] + 32;
                }
            }
            
            if (check_range(sightings[i].species[a], sightings[i].species[a + 1]) == 0) {
                int x = 0;
                while (sightings[i].species[x] != '\0') {
                    sightings[i].species[x] = sightings[i].species[x + 1];
                    x++;
                }
                checka = 1;
            }
            
            if (checka == 1) {
                a--;
            }
            a++;
        }
        i++;printf("\n");
    }
    
}

int check_range(int target, int target_next) {
    int result = 0;
    if (target >= 97 && target <= 122) {
        result = 1;
    }
    if (target >= 97 && target <= 122) {
        result = 1;
    }
    if (target == 45 && target_next != 80 && target_next != 102) {
        result = 1;
    }
    if (target == 32 && target_next == 32) {
        result = 1;
    }

    return result;
}
