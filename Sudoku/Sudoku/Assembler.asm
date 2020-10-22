.CODE

	push rax
	push rbx
	push rcx
	push rdx

asmCheckSudoku PROC ; int *tab
	mov rsi, rcx	 ; rsi wskaznik duzej petli
	mov dh,	9h		 ; licznik duzej petli
PetlaD9:
	mov ax, 0b		 ; biotowa zawartosc jedenej 9
	mov rdi, rsi	 ; rdi wskaznik malej petli
	mov dl, 9h		 ; licznik malej petli
Petla9:
	mov bx, 0000000000000001b	;tworzy przypisanie
	mov cl, [rdi] - 1	; ustawia odpowiedni bit BLAAAAAAADDDDDDDD
	
	shl bx, cl		; przesuwa bitowo
	add ax, bx		; dodaje bit do wektora sprawdzajacego
	inc rdi			; inkrementuje pozycje odczytywana z tablicy
	dec dl			; dekrementuje licznik malej petli
	cmp dl, 0h		; sprawdzenie czy koniec petli malej
	je Sprawdz		; skok do sprawdzenia 9
	jmp Petla9		; skok na poczatek petli malej
Sprawdz:
	cmp ax, 0000000111111111b; sprawdzenie czy nie wystapilo powtorzenie
	Je Skok
	mov rax, 0
	pop rdx
	pop rcx
	pop rbx
	pop rax
	ret

	Skok:
	dec dh; dekrementuje liczik duzej petli
	cmp dh, 0h ; sprawdzenie czy koniec petli duzej
	je PetlaD9 ; skok na poczatek petli duzej

	MOV RAX, 1
	
	pop rdx
	pop rcx
	pop rbx
	pop rax
	ret
asmCheckSudoku ENDP
END