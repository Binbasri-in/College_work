    AREA ASC,CODE,READONLY
CNT RN R0                   ;set CNT name as counter
    MOV CNT,#0              ;set CNT to 0
    LDR R1,=ARRAY           ;R1 points to ARRAY which is the input
    LDR R2,=ORDER           ;R2 points to ORDER which is where we will store the result

COPY                        ;copy the elements from ARRAY to ORDER
    LDR R3,[R1],#4          ;load the element from ARRAY to R3 and increment R1 by 4
    CMP R3,#0               ;compare R3 with 0
    BEQ LOOP                ;if R3 is 0 then jump to LOOP
    STR R3,[R2],#4          ;store R3 to ORDER and increment R2 by 4
    ADD CNT,#1              ;increment CNT by 1
    B COPY                  ;jump to COPY

LOOP                        ;bubble sort takes place
    MOV R5,#0               ;set R5 to 0        i = 0
    CMP CNT,#0              ;compare CNT with 0
    BEQ STOP                ;if CNT is 0 then jump to STOP

REPEAT
    MOV R1,#0               ;set R1 to 0            j = 0
    LDR R2,=ORDER           ;R2 points to ORDER

NEXTVAL
    ADD R1,#1               ;increment R1 by 1    j++
    CMP R1,CNT              ;compare R1 with CNT    
    BEQ RLOOP               ;if R1 is equal to CNT then jump to RLOOP   
    LDR R3,[R2],#4          ;load the element from ORDER to R3 and increment R2 by 4    load a[j]
    LDR R4,[R2]             ;load the element from ORDER to R4                    load a[j+1]   
    CMP R3,R4               ;compare R3 with R4                        if a[j] > a[j+1] then swap them
    BLS NEXTVAL             ;if R3 is less than or equal to R4 then jump to NEXTVAL 
    SUB R2,#4               ;decrement R2 by 4  
    STR R4,[R2],#4          ;store R4 to ORDER and decrement R2 by 4
    STR R3,[R2]            ;store R3 to ORDER
    B NEXTVAL               ;jump to NEXTVAL

RLOOP
    ADD R5,#1               ;increment R5 by 1  i++
    CMP R5,CNT              ;compare R5 with CNT
    BNE REPEAT              ;if R5 is not equal to CNT then jump to REPEAT

STOP   B STOP               ;infinite loop

ARRAY DCD 0x00000004,0x00000006,0x00000005,0x00000002,0x00000001
ARRAYEND DCD 0

    AREA ARR,DATA,READWRITE
ORDER
    END
