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
    
    char mess_alpha[n_sightings][MAX_SPECIES_NAME_LENGTH];
    int i = 0;
    while (i < n_sightings) {
        
        int a = 0;
        int b = 0;
        while (sightings[i].species[a] != '\0') {
            if (sightings[i].species[a] >= 65 && sightings[i].species[a] <= 90) {
                sightings[i].species[a] = sightings[i].species[a] + 32;    
            }
            if (sightings[i].species[a] >= 97 && sightings[i].species[a] <= 122 ) {
                mess_alpha[i][b] = sightings[i].species[a];
                b++;  
                mess_alpha[i][b] = '\0';
            }
            a++;
        }
        i++;
    }
    
    
// char species_names_file[], int n_sightings, struct pod sightings[n_sightings]
    // Read the correct name file to an array
    FILE *f = fopen(species_names_file, "r");
    char right_name[MAX_WHALE_SPECIES][MAX_SPECIES_NAME_LENGTH];
    int v = 0;
    while (fgets(right_name[v], MAX_SPECIES_NAME_LENGTH, f)) {
        v++;
    }
    
    char right_nam[MAX_WHALE_SPECIES][MAX_SPECIES_NAME_LENGTH];
        int cv = 0;
        while (cv <= v) {
            int bn = 0;
            while (right_name[cv][bn] != '\n' && right_name[cv][bn] != '\0') {
                right_nam[cv][bn] = right_name[cv][bn];
                bn++;
            }
            cv++;
        }
    
    char right_names[MAX_WHALE_SPECIES][MAX_SPECIES_NAME_LENGTH];
    int h = 0;
    while (h <= v) {
        strcpy(right_names[h], right_name[h]);
        h++;
    }
    
    char right_names_alpha[MAX_WHALE_SPECIES][MAX_SPECIES_NAME_LENGTH];
    int w = 0;
    while (w <= v) {
        int c = 0;
        int d = 0;
        while (right_names[w][c] != '\0') {
            if (right_names[w][c] >= 'A' && right_names[w][c] <= 'Z') {
                right_names[w][c] = right_names[w][c] + 32;    
            }
            if (right_names[w][c] >= 97 && right_names[w][c] <= 122 ) {
                right_names_alpha[w][d] = right_names[w][c];
                d++;  
                right_names_alpha[w][d] = '\0';
            }
            c++;
        } 
        w++;  
    }

    int index1 = 0;
    while (index1 < n_sightings) {
        int index2 = 0;
        while (index2 < w) {
            if (strcmp(right_names_alpha[index2], mess_alpha[index1]) == 0) {
                strcpy(sightings[index1].species, right_nam[index2]);
            }
            index2++;
        }
        index1++;
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
