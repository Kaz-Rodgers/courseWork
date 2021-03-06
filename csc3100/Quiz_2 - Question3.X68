*-----------------------------------------------------------
* Title      : QUIZ 2 QUESTION 3
* Written by : CALEB LATIMER 
* Date       : 12/4/2016
* Description: SORTING ARRAY 
*-----------------------------------------------------------
    ORG    $1000
START:                  ; first instruction of program

* Put program code here
    ; D2 = SMALLEST ELEMENT
    ; D3 = COUNTER
    ; D4 = PREVIOUSMIN
    ; D5 = 2ND MING
    ; D6 = 3RD MIN 
   
    
    LEA MES, A1 ; INITAL MESSAGE 
    MOVE #14,D0
    TRAP #15
    
 
    LEA ARR,A2 ; LOAD ARRAY INTO A2 
    LEA SPACE,A1 ; LOAD SPACE INTO A1
    MOVE.L (A2),D1 ; MOVE THE FIRST BIT OF A1 INTO D1
    BRA LOOPMIN
    
LOOPMIN ; LOOP TO ITERATE THROUGH THE ARRAY AND SAVE THE SMALLEST ELEMENT
    MOVE.L (A2)+,D2
    CMP D1,D2
    BLT NEWMIN
    BGE LOOPMINCOUNT
    
NEWMIN ; UPDATE D2 WITH THE MOST SMALLEST ELEMENT, USE OF LONG TO ACCOUNT FOR NEGATIVE NUMBER 
    MOVE.L D2,D1
    BRA LOOPMINCOUNT
    
LOOPMINCOUNT ; COUNTER FOR LOOPMIN HANDLED HERE, DECIDES IF LOOP CONTINUES OR WE MOVE TO PRINT
    ADD.B #1,D3
    CMP #4,D3
    BEQ PRINT
    BNE LOOPMIN
    
PRINT ; PRINT SMALLEST ELEMENT AND A SPACE
    MOVE.L #3,D0
    TRAP #15
    
    MOVE #14,D0
    TRAP #15
    
    
    ; ^ FIRST PASS PRINTS -1 EACH SUCCESSIVE PASS DOES THE SAME BUT DIFFERENT OUTPUT AND STORES THE NEW VALUE IN A DIFFERENT REGISTER
    
    
    
    MOVE.L D1,D4 ; STORE -1 IN D4 FOR LATER COMPARISON
    LEA ARR,A2 ; RELOAD ARRAY 
    MOVE.L (A2),D1 ; MAKE D1 THE FIRST THING IN THE ARRAY 
    CLR.L D3 ; CLEAR LOOP COUNTER
    BRA LOOPMIN2 ; BRANCH TO NEXT LOOP 
    
LOOPMIN2
    MOVE.L (A2)+,D2
    CMP D1,D2
    BLT NEWMIN2
    BGE LOOPMINCOUNT2
    
NEWMIN2 ; COMPARE CURRENT SMALLEST VALUE WITH THE PREVIOUSLY KNOWN SMALLEST VALUE 
    CMP D4,D2
    BEQ LOOPMINCOUNT2
    BNE UPDATEMIN
    
UPDATEMIN ; UPDATE MIN IF THERE ARE NEW VALUES 
    MOVE.L D2,D1
    BRA LOOPMINCOUNT2
    
LOOPMINCOUNT2 ; COUNTER FOR THE LOOP 
    ADD.B #1,D3
    CMP #4,D3
    BEQ PRINT2
    BNE LOOPMIN2
    
PRINT2 ; OUTPUT SECOND SMALLEST VALUE AND A SPACE
    MOVE.L #3,D0
    TRAP #15
    
    MOVE #14,D0
    TRAP #15
    
 
    
    
    ; ^ PRINTS THE 0 
    
    
    
    MOVE.L D1,D5 ; STORE 0 IN D5 FOR LATER COMPARISON
    LEA ARR,A2 ; RELOAD ARRAY 
    MOVE.L (A2),D1 ; MAKE D1 THE FIRST THING IN THE ARRAY 
    CLR.L D3 ; CLEAR LOOP COUNTER
    BRA LOOPMIN3 ; BRANCH TO NEXT LOOP 
    
LOOPMIN3
    MOVE.L (A2)+,D2
    CMP D1,D2
    BLT NEWMIN3
    BGE LOOPMINCOUNT3
    
NEWMIN3
    CMP D4,D2
    BEQ LOOPMINCOUNT3
    BNE NEXTCOMP
    
NEXTCOMP
    CMP D5,D2
    BEQ LOOPMINCOUNT3
    BNE UPDATEMIN2
    
UPDATEMIN2
    MOVE.L D2,D1
    BRA LOOPMINCOUNT3
    
LOOPMINCOUNT3
    ADD.B #1,D3
    CMP #4,D3
    BEQ PRINT3
    BNE LOOPMIN3
    
PRINT3 ; OUTPUT NEXT VALUE AND A SPACE
    MOVE.L #3,D0
    TRAP #15
    
    MOVE #14,D0
    TRAP #15
    



; ^ PRINTS THE 3



    MOVE.L D1,D6 ; STORE 3 IN D6 FOR LATER COMPARISON
    LEA ARR,A2 ; RELOAD ARRAY 
    MOVE.L (A2),D1 ; MAKE D1 THE FIRST THING IN THE ARRAY 
    CLR.L D3 ; CLEAR LOOP COUNTER
    BRA LOOPMIN4 ; BRANCH TO NEXT LOOP 
    
LOOPMIN4
    MOVE.L (A2)+,D2
    CMP D1,D2
    BLT NEWMIN4
    BGE LOOPMINCOUNT4
    
NEWMIN4
    CMP D4,D2
    BEQ LOOPMINCOUNT4
    BNE NEXTCOMP2
    
NEXTCOMP2 
    CMP D5,D2
    BEQ LOOPMINCOUNT4
    BNE NEXTCOMP3
    
NEXTCOMP3
    CMP D6,D2
    BEQ LOOPMINCOUNT4
    BNE UPDATEMIN3
    
UPDATEMIN3
    MOVE.L D2,D1
    BRA LOOPMINCOUNT4
    
LOOPMINCOUNT4
    ADD.B #1,D3
    CMP #4,D3
    BEQ PRINT4
    BNE LOOPMIN4
    
PRINT4 ; OUTPUT FINAL VALUE 
    MOVE.L D2,D1
    MOVE.L #3,D0
    TRAP #15
    ; ^ PRINTS 4

    
    SIMHALT             ; halt simulator

* Put variables and constants here
ARR DC.L 3, -1, 0, 4
MES DC.B 'The sorted array is: ',0 
SPACE DC.B ' ',0
    END    START        ; last line of source

*~Font name~Courier New~
*~Font size~10~
*~Tab type~1~
*~Tab size~4~
