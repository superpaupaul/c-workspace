/*
    
    .___ ____ ______________     .___       ____   ____     .__  .__               
    |   |    |   \__    ___/   __| _/____   \   \ /   /____ |  | |__|__________.__.
    |   |    |   / |    |     / __ |/ __ \   \   Y   // __ \|  | |  \___   <   |  |
    |   |    |  /  |    |    / /_/ \  ___/    \     /\  ___/|  |_|  |/    / \___  |
    |___|______/   |____|    \____ |\___  >    \___/  \___  >____/__/_____ \/ ____|
                                \/    \/                \/              \/\/    

*/
#include <stdio.h>
#include <stdlib.h>
int main( int argc, char * argv[] ) {
    // commande shell permettant de rediriger une sortie : >
    printf(" stdin : %d stdout: %d  stderr: %d \n",fileno(stdin),fileno(stdout),fileno(stderr));
}