#include "people.h"

int main(){
    People*** people = init_people();  
    init_names(&(*people)[0], "Krum", "Stefanov");
/*     get_names(people);
 */    return 0;
}