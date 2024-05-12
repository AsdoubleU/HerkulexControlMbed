#include "mbed.h"
#include "herkulex.h"

Herkulex sv(D8, D2, 115200); // 시리얼 포트와 보드레이트 설정

int main() {

    // sv.getStatus(2);

    for (size_t i=0;i<4;i++){
        sv.clear(i);
        sv.setTorque(i, TORQUE_ON); 
        wait(0.001);
    }

    sv.getPos(2);
    
    while(true) {

        for(size_t i=0;i<4;i++){ 
            sv.positionControl(i, 1002, 100, GLED_ON); 
            wait(0.001);
        }

        wait(5);
        for(size_t i=0;i<4;i++){ 
            sv.positionControl(i, 512, 100, BLED_ON); 
            wait(0.001);
        }
        wait(5);

        for(size_t i=0;i<4;i++){ 
            sv.positionControl(i, 21, 100, RLED_ON); 
            wait(0.001);
        }
        wait(5);


        for(size_t i=0;i<4;i++){ 
            sv.clear(i); 
            wait(0.001);
        }

    }
}
