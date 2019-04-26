int standard_offset(int town) {
    if(town == 0) {
        return TIMEZONE_ACST_OFFSET;
    }
    else if(town == 1) {
        return TIMEZONE_AEST_OFFSET;
    }
    else if(town == 2) {
        return TIMEZONE_ACST_OFFSET;
    } 
    else if(town == 3) {
        return TIMEZONE_AEST_OFFSET;
    } 
    else if(town == 4) {
        return TIMEZONE_ACST_OFFSET;
    } 
    else if(town == 5) {
        return TIMEZONE_ACWST_OFFSET;
    } 
    else if(town == 6) {
        return TIMEZONE_AEST_OFFSET;
    } 
    else if(town == 7) {
        return TIMEZONE_LHST_OFFSET;
    } 
    else if(town == 8) {
        return TIMEZONE_AEST_OFFSET;
    } 
    else if(town == 9) {
        return TIMEZONE_AWST_OFFSET;
    } 
    else if(town == 10) {
        return TIMEZONE_AEST_OFFSET;
    } 
    else if(town == 11) {
        return TIMEZONE_NZST_OFFSET;
    } 
    else if(town == 12) {
        return TIMEZONE_NZST_OFFSET;
    } 
    else if(town == 13) {
        return TIMEZONE_NZST_OFFSET;
    }
    else {
        return -1;
    }
} 
    
int stamp1(int town) {
        if(town == 0) {
            return TOWN_ADELAIDE_DELTA_TIMESTAMP_1;
        }
        else if(town == 1) {
            return TOWN_BRISBANE_DELTA_TIMESTAMP_1;
        }
        else if(town == 2) {
            return TOWN_BROKEN_HILL_DELTA_TIMESTAMP_1;
        } 
        else if(town == 3) {
            return TOWN_CANBERRA_DELTA_TIMESTAMP_1;
        } 
        else if(town == 4) {
            return TOWN_DARWIN_DELTA_TIMESTAMP_1;
        } 
        else if(town == 5) {
            return TOWN_EUCLA_DELTA_TIMESTAMP_1;
        } 
        else if(town == 6) {
            return TOWN_HOBART_DELTA_TIMESTAMP_1;
        } 
        else if(town == 7) {
            return TOWN_LORD_HOWE_IS_DELTA_TIMESTAMP_1; 
        } 
        else if(town == 8) {
            return TOWN_MELBOURNE_DELTA_TIMESTAMP_1;
        } 
        else if(town == 9) {
            return TOWN_PERTH_DELTA_TIMESTAMP_1;
        } 
        else if(town == 10) {
            return TOWN_SYDNEY_DELTA_TIMESTAMP_1;
        } 
        else if(town == 11) {
            return TOWN_AUCKLAND_DELTA_TIMESTAMP_1;
        } 
        else if(town == 12) {
            return TOWN_CHRISTCHURCH_DELTA_TIMESTAMP_1;
        } 
        else if(town == 13) {
            return TOWN_WELLINGTON_DELTA_TIMESTAMP_1;
        }
        else {
            return -1; 
        }
}
    
int stamp2(int town) {
        if(town == 0) {
            return TOWN_ADELAIDE_DELTA_TIMESTAMP_2;
        }
        else if(town == 1) {
            return TOWN_BRISBANE_DELTA_TIMESTAMP_2;
        }
        else if(town == 2) {
            return TOWN_BROKEN_HILL_DELTA_TIMESTAMP_2;
        } 
        else if(town == 3) {
            return TOWN_CANBERRA_DELTA_TIMESTAMP_2;
        } 
        else if(town == 4) {
            return TOWN_DARWIN_DELTA_TIMESTAMP_2;
        } 
        else if(town == 5) {
            return TOWN_EUCLA_DELTA_TIMESTAMP_2;
        } 
        else if(town == 6) {
            return TOWN_HOBART_DELTA_TIMESTAMP_2;
        } 
        else if(town == 7) {
            return TOWN_LORD_HOWE_IS_DELTA_TIMESTAMP_2;
        } 
        else if(town == 8) {
            return TOWN_MELBOURNE_DELTA_TIMESTAMP_2;
        } 
        else if(town == 9) {
            return TOWN_PERTH_DELTA_TIMESTAMP_2;
        } 
        else if(town == 10) {
            return TOWN_SYDNEY_DELTA_TIMESTAMP_2;
        } 
        else if(town == 11) {
            return TOWN_AUCKLAND_DELTA_TIMESTAMP_2;
        } 
        else if(town == 12) {
            return TOWN_CHRISTCHURCH_DELTA_TIMESTAMP_2;
        } 
        else if(town == 13) {
            return TOWN_WELLINGTON_DELTA_TIMESTAMP_2;  
        } 
        else {
            return -1;
        }
}
    
    
    
    
    
    
    
    
    
#define TOWN_ADELAIDE_DELTA_TIMESTAMP_1 697640
#define TOWN_BRISBANE_DELTA_TIMESTAMP_1 697600
#define TOWN_BROKEN_HILL_DELTA_TIMESTAMP_1 697640
#define TOWN_CANBERRA_DELTA_TIMESTAMP_1 697600
#define TOWN_DARWIN_DELTA_TIMESTAMP_1 697640
#define TOWN_EUCLA_DELTA_TIMESTAMP_1 697640
#define TOWN_HOBART_DELTA_TIMESTAMP_1 697600
#define TOWN_LORD_HOWE_IS_DELTA_TIMESTAMP_1 697640
#define TOWN_MELBOURNE_DELTA_TIMESTAMP_1 697600
#define TOWN_PERTH_DELTA_TIMESTAMP_1 697600
#define TOWN_SYDNEY_DELTA_TIMESTAMP_1 697600
#define TOWN_AUCKLAND_DELTA_TIMESTAMP_1 697600
#define TOWN_CHRISTCHURCH_DELTA_TIMESTAMP_1 697600
#define TOWN_WELLINGTON_DELTA_TIMESTAMP_1 697600
#define TOWN_ADELAIDE_DELTA_TIMESTAMP_2 7640
#define TOWN_BRISBANE_DELTA_TIMESTAMP_2 7600
#define TOWN_BROKEN_HILL_DELTA_TIMESTAMP_2 7640
#define TOWN_CANBERRA_DELTA_TIMESTAMP_2 7600
#define TOWN_DARWIN_DELTA_TIMESTAMP_2 7640
#define TOWN_EUCLA_DELTA_TIMESTAMP_2 7640
#define TOWN_HOBART_DELTA_TIMESTAMP_2 7600
#define TOWN_LORD_HOWE_IS_DELTA_TIMESTAMP_2 7640
#define TOWN_MELBOURNE_DELTA_TIMESTAMP_2 7600
#define TOWN_PERTH_DELTA_TIMESTAMP_2 7600
#define TOWN_SYDNEY_DELTA_TIMESTAMP_2 7600
#define TOWN_AUCKLAND_DELTA_TIMESTAMP_2 7600
#define TOWN_CHRISTCHURCH_DELTA_TIMESTAMP_2 7600
#define TOWN_WELLINGTON_DELTA_TIMESTAMP_2 7600
// The existance of socalled "delta timestamp" is caused by the tramsformation of decimal system(timestamp) and other system(days in a month).





















