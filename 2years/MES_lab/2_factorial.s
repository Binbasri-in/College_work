      AREA FACTORIAL,CODE,READONLY
START
    MOV R0,#5  ; R0 = 5
    MOV R1,R0   ; R1 = R0

AGAIN
    SUB R0,#1   ; R0 = R0 - 1
    MUL R1,R0,R1   ; R1 = R0 * R1
    CMP R0,#1   ; R0 - 0 == 0?
    BNE AGAIN   ; if not equal, jump to AGAIN

LOOP B LOOP ; infinite loop

    END
