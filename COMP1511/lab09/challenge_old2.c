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
    char input[n_sightings][MAX_SPECIES_NAME_LENGTH];
    int i = 0;
    while (i < n_sightings) {
        // new method is only compare the alphabetic characters
        int a = 0;
        int b = 0;
        while (sightings[i].species[a] != '\0') {
            if (sightings[i].species[a] >= 65 && sightings[i].species[a] <= 90) {
                sightings[i].species[a] = sightings[i].species[a] + 32;    
            }
            if (sightings[i].species[a] >= 97 && sightings[i].species[a] <= 122 ) {
                input[i][b] = sightings[i].species[a];
                b++;  
                input[i][b] = '\0';
            }
            a++;
        }
        i++;
    }  

    int d = 0;
    while (d < n_sightings) {
        if (strcmp(input[d], "pygmyrightwhale") == 0) {
            strcpy(sightings[d].species, "Pygmy right whale");
        }
        if (strcmp(input[d], "southernrightwhale") == 0) {
            strcpy(sightings[d].species, "Southern right whale");
        }
        if (strcmp(input[d], "stripeddolphin") == 0) {
            strcpy(sightings[d].species, "Striped dolphin");
        }
        if (strcmp(input[d], "commondolphin") == 0) {
            strcpy(sightings[d].species, "Common dolphin");
        }
        if (strcmp(input[d], "bluewhale") == 0) {
            strcpy(sightings[d].species, "Blue whale");
        }
        if (strcmp(input[d], "dwarfspermwhale") == 0) {
            strcpy(sightings[d].species, "Dwarf sperm whale");
        }
        if (strcmp(input[d], "spinnerdolphin") == 0) {
            strcpy(sightings[d].species, "Spinner dolphin");
        }
        if (strcmp(input[d], "indopacifichumpbackeddolphin") == 0) {
            strcpy(sightings[d].species, "Indo-Pacific humpbacked dolphin");
        }
        if (strcmp(input[d], "longfinnedpilotwhale") == 0) {
            strcpy(sightings[d].species, "Long-finned pilot whale");
        }
        if (strcmp(input[d], "shortfinnedpilotwhale") == 0) {
            strcpy(sightings[d].species, "Short-finned pilot whale");
        }
        if (strcmp(input[d], "dwarfminkewhale") == 0) {
            strcpy(sightings[d].species, "Dwarf minke whale");
        }
        if (strcmp(input[d], "orca") == 0) {
            strcpy(sightings[d].species, "Orca");
        }
        if (strcmp(input[d], "pygmyspermwhale") == 0) {
            strcpy(sightings[d].species, "Pygmy sperm whale");
        }
        if (strcmp(input[d], "humpbackwhale") == 0) {
            strcpy(sightings[d].species, "Humpback whale");
        }
        if (strcmp(input[d], "finwhale") == 0) {
            strcpy(sightings[d].species, "Fin whale");
        }
        if (strcmp(input[d], "coastalbottlenosedolphin") == 0) {
            strcpy(sightings[d].species, "Coastal bottlenose dolphin");
        }
        if (strcmp(input[d], "seiwhale") == 0) {
            strcpy(sightings[d].species, "Sei whale");
        }
        if (strcmp(input[d], "brydeswhale") == 0) {
            strcpy(sightings[d].species, "Bryde's whale");
        }
        if (strcmp(input[d], "andrewsbeakedwhale") == 0) {
            strcpy(sightings[d].species, "Andrew’s beaked whale");
        }
        if (strcmp(input[d], "beakedwhale") == 0) {
            strcpy(sightings[d].species, "Beaked whale");
        }
        if (strcmp(input[d], "pealesdolphin") == 0) {
            strcpy(sightings[d].species, "Peale’s dolphin");
        }
        d++;
    }

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
