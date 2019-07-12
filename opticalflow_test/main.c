//
// Created by h on 19. 6. 18.
//

#include <stdio.h>
#include "app.h"

int main() {

    char *argv[3];
    argv[0] = "../img_00001.jpg";
    argv[1] = "../img_00002.jpg";
    argv[2] = "/home/h/project/dataset/fire_alert/S1_BMT/VID_20190423_185306.mp4";


    split(argv);
    run(argv);

}