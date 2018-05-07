.name "Provencal"
.comment "f"


	ld %1, r8
	sti r1, %:jump, %0
	fork %24

add:
	sti r1, %:live, %1
	and r1, %0, r2

live:
	live %1
	zjmp %:live

	sti r1, %:add2, %1
add2:
	live %1
	fork %:jump

	sti r1, %:aff, %1
	and r1, %0, r2
aff:
	live %1
	ld %99, r2
	ld %111, r3
	ld %117, r4
	ld %0, r5
	aff r2
	aff r3
	aff r4
	aff r2
	aff r3
	aff r4
	aff r5
	zjmp %:aff
jump:
	live %1
	sti r1, %200, %200
