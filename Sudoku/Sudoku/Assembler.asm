.CODE

asmCheckSudoku PROC ; int *tab

	push rbx
	push rcx
	push rdx

PoczatekWiersze:
	mov rax, rcx
	mov rdi, rcx	 ; rdi wskaznik duzej petli
	mov dh,	9h		 ; licznik duzej petli
WierszeD9:
	mov r10, 0b		 ; biotowa zawartosc jedenej 9
	mov dl, 9h		 ; licznik malej petli
Wiersze9:
	mov r9, 0000000000000001b	;tworzy przypisanie
	mov cl, [rdi] 	; ustawia odpowiedni bit BLAAAAAAADDDDDDDD
	dec cl
	shl r9, cl		; przesuwa bitowo
	add r10, r9		; dodaje bit do wektora sprawdzajacego
	add rdi, 4		; inkrementuje pozycje odczytywana z tablicy
	dec dl			; dekrementuje licznik malej petli
	cmp dl, 0h		; sprawdzenie czy koniec petli malej
	je SprawdzW		; skok do sprawdzenia 9
	jmp Wiersze9	; skok na poczatek petli malej

SkokW:
	dec dh			; dekrementuje liczik duzej petli
	cmp dh, 0h		; sprawdzenie czy koniec petli duzej
	je PoczatekKolumny		; skok na koniec programu
	jmp WierszeD9	; skok na poczatek petli duzej

SprawdzW:
	cmp r10, 511; sprawdzenie czy nie wystapilo powtorzenie
	Je SkokW
	pop rdx
	pop rcx
	pop rbx
	mov rax, 0
	ret



PoczatekKolumny:
	mov rdi, rax	 ; rdi wskaznik duzej petli
	mov rsi, rax
	mov dh,	9h		 ; licznik duzej petli
KolumnyD9:
	mov rdi, rsi
	mov r10, 0b		 ; biotowa zawartosc jedenej 9
	mov dl, 9h		 ; licznik malej petli
Kolumny9:
	mov r9, 0000000000000001b	;tworzy przypisanie
	mov cl, [rdi] 	; ustawia odpowiedni bit BLAAAAAAADDDDDDDD
	dec cl
	shl r9, cl		; przesuwa bitowo
	add r10, r9		; dodaje bit do wektora sprawdzajacego
	mov bl, 9

Petla1:
	add rdi, 4		; inkrementuje pozycje odczytywana z tablicy
	dec bl
	cmp bl, 0h
	je Skok1
	jmp Petla1

Skok1:
	dec dl			; dekrementuje licznik malej petli
	cmp dl, 0h		; sprawdzenie czy koniec petli malej
	je SprawdzK		; skok do sprawdzenia 9
	jmp Kolumny9	; skok na poczatek petli malej

SkokK:
	dec dh			; dekrementuje liczik duzej petli
	cmp dh, 0h		; sprawdzenie czy koniec petli duzej
	je PoczatekDziew		; skok na koniec programu
	add rsi, 4
	jmp KolumnyD9	; skok na poczatek petli duzej

SprawdzK:
	cmp r10, 511; sprawdzenie czy nie wystapilo powtorzenie
	Je SkokK
	pop rdx
	pop rcx
	pop rbx
	mov rax, 0
	ret



PoczatekDziew:
	mov rdi, rax	 
	mov rsi, rax
	mov dh,	3h		 ; licznik duzej petli
DziewD9:
	mov rdi, rsi
	mov bh, 3
DziewP9:
	mov r10, 0b		 ; biotowa zawartosc jedenej 9
	mov dl, 9h
Dziew9:
	mov bl, 3
PoWierszu:
	mov r9, 0000000000000001b	;tworzy przypisanie
	mov cl, [rdi] 	; ustawia odpowiedni bit BLAAAAAAADDDDDDDD
	dec cl
	shl r9, cl		; przesuwa bitowo
	add r10, r9		; dodaje bit do wektora sprawdzajacego
	add rdi, 4		; inkrementuje pozycje odczytywana z tablicy
	dec dl			; dekrementuje licznik malej petli
	dec bl
	cmp bl, 0
	je Kontynuuj
	jmp PoWierszu

Kontynuuj:
	mov bl, 6
	cmp dl, 0h		; sprawdzenie czy koniec petli malej
	je SprawdzD		; skok do sprawdzenia 9
	jmp Przeskok	; skok na poczatek petli malej

Przeskok:
	add rdi, 4		; inkrementuje pozycje odczytywana z tablicy
	dec bl
	cmp bl, 0h
	je Dziew9
	jmp Przeskok

SkokD:
	dec bh
	cmp bh, 0
	je SkokDK
	mov bl, 6

PrzeskokPoSpr:
	add rdi, 4		; inkrementuje pozycje odczytywana z tablicy
	dec bl
	cmp bl, 0h
	je DziewP9
	jmp PrzeskokPoSpr

SkokDK:
	dec dh			; dekrementuje liczik duzej petli
	cmp dh, 0h		; sprawdzenie czy koniec petli duzej
	je Koniec		; skok na koniec programu
	mov bl, 3
	jmp Przeskok2		; skok na poczatek petli duzej

Przeskok2:
	add rsi, 4		; inkrementuje pozycje odczytywana z tablicy
	dec bl
	cmp bl, 0h
	je DziewD9
	jmp Przeskok2

SprawdzD:
	cmp r10, 511	; sprawdzenie czy nie wystapilo powtorzenie
	Je SkokD
	pop rdx
	pop rcx
	pop rbx
	mov rax, 0
	ret


Koniec:
	pop rdx
	pop rcx
	pop rbx
	MOV RAX, 1
	ret

asmCheckSudoku ENDP
END