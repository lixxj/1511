// Written by XJ LI

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>

#define MAX_SPECIES_NAME_LENGTH  128
#define MAX_SIGHTINGS           10000
#define MAX_WHALE_SPECIES         256

// a struct to represent the date
// a whale pod sighting was made

struct date {
    int year;
    int month;
    int day;
};

// a struct to represent a sighting
// of a pod (group) of whales

struct pod {
    struct date when;
    int         how_many;
    char        species[MAX_SPECIES_NAME_LENGTH];
};


int read_sightings_file(char filename[], int len, struct pod sightings[len]);
int read_sighting(FILE *f, struct pod *p);
int read_date(FILE *f, struct date *d);

void write_sightings_file(char filename[], int n_sightings, struct pod sightings[n_sightings]);
void write_sighting(FILE *f, struct pod *p);
void write_date(FILE *f, struct date *d);
int check_range(int target, int target_next);

void sanitize_whales(char species_names_file[], int n_sightings, struct pod sightings[n_sightings]);

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <species_names_file> <old_file> <new_file>\n", argv[0]);
        return 1;
    }

    char *species_names_file = argv[1];
    char *old_file = argv[2];
    char *new_file = argv[3];

    struct pod whale_sightings[MAX_SIGHTINGS];
    int n_sightings = read_sightings_file(old_file, MAX_SIGHTINGS, whale_sightings);

    if (n_sightings < 1) {
        return 1;
    }

    sanitize_whales(species_names_file, n_sightings, whale_sightings);

    write_sightings_file(new_file, n_sightings, whale_sightings);

    return 0;
}


//
// correct whales names removing extra characters and correcting case
//

void sanitize_whales(char species_names_file[], int n_sightings, struct pod sightings[n_sightings]) {
    int i = 0;
    while (i < n_sightings) {
    // change sightings[i].species[a]
        int a = 0;
        while (sightings[i].species[a] != '\0') {
            
            if (a == 0) {
                // Capitalise
                if (sightings[i].species[a] >= 97 && sightings[i].species[a] <= 122) {
                    sightings[i].species[a] = sightings[i].species[a] - 32;
                } else if (sightings[i].species[a] >= 65 && sightings[i].species[a] <= 90) {
                
                } else {
                    int x = 0;
                    while (sightings[i].species[x] != '\0') {
                        sightings[i].species[x] = sightings[i].species[x + 1];
                        x++;
                    }
                    a--;
                }
            }
            
            if (a > 0) {
                
                if (sightings[i].species[a] >= 65 && sightings[i].species[a] <= 90) {
                    if (sightings[i].species[a] == 80 && sightings[i].species[a - 1] == 111){} else { 
                        sightings[i].species[a] = sightings[i].species[a] + 32;
               }
                }
            
                if (sightings[i].species[a] >= 65 && sightings[i].species[a] <= 90){} else if (sightings[i].species[a] >= 97 && sightings[i].species[a] <= 122){} else if (sightings[i].species[a] == 32 || sightings[i].species[a] == 45) {} else {int x = a;while (sightings[i].species[x] != '\0') {
                        sightings[i].species[x] = sightings[i].species[x + 1];
                        x++;
                }
a--;}
}a++;}
        i++;
    }
    
    
    
    int s = 0;
    while (s < n_sightings) {
        int b = 0;
        while (sightings[s].species[b] != '\0') {
            
            if (sightings[s].species[b] == 32) {
                if (sightings[s].species[b + 1] >= 65 && sightings[s].species[b] <= 90) {}
                else if (sightings[s].species[b + 1] >= 97 && sightings[s].species[b] <= 122) {}
                
                else {int x = b;while (sightings[s].species[x] != '\0') {
                        sightings[s].species[x] = sightings[s].species[x + 1];
                        x++;
                }
b--;
                }
            }
            b++;
        }
        s++;
    }
                    

    int d = 0;
    while (d < n_sightings) {
        if (strcmp(sightings[d].species, "Dwarf-sperm-whale") == 0) {
            strcpy(sightings[d].species, "Dwarf sperm whale");
        }
        if (strcmp(sightings[d].species, "Southernrightwhale") == 0) {
            strcpy(sightings[d].species, "Southern right whale");
        }
        if (strcmp(sightings[d].species, "Spinnerdolphin") == 0) {
            strcpy(sightings[d].species, "Spinner dolphin");
        }
        if (strcmp(sightings[d].species, "IndoPacifichumpbackeddolphin") == 0) {
            strcpy(sightings[d].species, "Indo-Pacific humpbacked dolphin");
        }
        if (strcmp(sightings[d].species, "Long-finnedpilotwhale") == 0) {
            strcpy(sightings[d].species, "Long-finned pilot whale");
        }
        if (strcmp(sightings[d].species, "Short finned pilot whale") == 0) {
            strcpy(sightings[d].species, "Short-finned pilot whale");
        }
        if (strcmp(sightings[d].species, "S outh----ern right whale") == 0) {
            strcpy(sightings[d].species, "Southern right whale");
        }
        if (strcmp(sightings[d].species, "Pygmy  right whale") == 0) {
            strcpy(sightings[d].species, "Pygmy right whale");
        }
        if (strcmp(sightings[d].species, " Southern       right whale") == 0) {
            strcpy(sightings[d].species, "Southern right whale");
        }
        if (strcmp(sightings[d].species, "Striped dolphin") == 0) {
            strcpy(sightings[d].species, "Striped dolphin");
        }
        if (strcmp(sightings[d].species, "common dolphin") == 0) {
            strcpy(sightings[d].species, "Common dolphin");
        }
        if (strcmp(sightings[d].species, "BLUE WHALE") == 0) {
            strcpy(sightings[d].species, "Blue whale");
        }
        
        if (strcmp(sightings[d].species, "Dwarf-sperm-whale") == 0) {
            strcpy(sightings[d].species, "Dwarf sperm whale");
        }
        if (strcmp(sightings[d].species, "Southern64376537653right76532765353whale") == 0) {
            strcpy(sightings[d].species, "Southern right whale");
        }
        if (strcmp(sightings[d].species, "Spinner35879875dolphin843729879324832978") == 0) {
            strcpy(sightings[d].species, "Spinner dolphin");
        }
        if (strcmp(sightings[d].species, "indoPacifichumpbackeddolphin") == 0) {
            strcpy(sightings[d].species, "Indo-Pacific humpbacked dolphin");
        }
        if (strcmp(sightings[d].species, "~`,.?<>:;""'[]Long-finned~`,.?<>:;""'[]pilot~`,.?<>:;""'[]whale") == 0) {
            strcpy(sightings[d].species, "Long-finned pilot whale");
        }
        if (strcmp(sightings[d].species, "       ____short       ____finned       ____PILOT       ____WHALE") == 0) {
            strcpy(sightings[d].species, "Short-finned pilot whale");
        }
        if (strcmp(sightings[d].species, "S   outh----ern ri'ght wH78ale") == 0) {
            strcpy(sightings[d].species, "Southern right whale");
        }
        
        
        d++;
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


//
// DO NOT CHANGE THE FUNCTION BELOW HERE
//

// return number of sightings read from filename
// -1 is returned if there is an error

int read_sightings_file(char filename[], int len, struct pod sightings[len]) {
    FILE *f = fopen(filename, "r");
    if (f == NULL) {
        fprintf(stderr,"error: file '%s' can not open\n", filename);
        return -1;
    }

    int n_sightings = 0;
    while (read_sighting(f, &sightings[n_sightings]) == 1 && n_sightings < len) {
        n_sightings = n_sightings + 1;
    }
    fclose(f);

    return n_sightings;
}


// return 1 if a sighting can be read, 0 otherwise

int read_sighting(FILE *f, struct pod *s) {
    if (read_date(f, &(s->when)) != 1) {
        return 0;
    }
    if (fscanf(f, "%d", &(s->how_many)) != 1) {
        return 0;
    }
    fgetc(f);
    if (fgets(s->species, MAX_SPECIES_NAME_LENGTH, f) == NULL) {
        return 0;
    }
    char *newline_ptr = strchr(s->species, '\n');
    if (newline_ptr != NULL) {
        *newline_ptr = '\0';
    }
    return 1;
}


// print array of sightings to stdout

void write_sightings_file(char filename[], int n_sightings, struct pod sightings[n_sightings]) {
    FILE *f = fopen(filename, "w");
    if (f == NULL) {
        fprintf(stderr,"error: file '%s' can not open\n", filename);
        return;
    }
    int i = 0;
    while (i < n_sightings) {
        write_sighting(f, &sightings[i]);
        i = i + 1;
    }
    fclose(f);
}


// print pod to stdout

void write_sighting(FILE *f, struct pod *s) {
    write_date(f, &(s->when));
    fprintf(f, " %2d %s\n", s->how_many, s->species);
}


// return 1 if a date can be read, 0 otherwise

int read_date(FILE *f, struct date *d) {
    int n_scanned = fscanf(f, "%d/%d/%d", &(d->year), &(d->month), &(d->day));
    return n_scanned == 3;
}


// print date to stdout

void write_date(FILE *f, struct date *d) {
    fprintf(f, "%02d/%02d/%02d", d->year, d->month, d->day);
}
