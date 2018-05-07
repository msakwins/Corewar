.name "Zork"
.comment "Je suis zork de lexemble de cheat sheet"

l2:	sti r1, %:live, %1
	ldi %:live, %1, r2
	and r1, %0, r8
live: live %42
	zjmp %:live
