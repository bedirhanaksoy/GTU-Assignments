	
	
	.data
	
	
	grid_count_input:	.asciiz "Please enter grid count: "
	col_count_input:	.asciiz "Please enter column count: "
	grid_input:		.asciiz "Please enter the entire grid in one line: "
	
	newline:		.asciiz "\n"
	
	grid_count:		.word 0			# grid count
	col_count:		.word 0			# column count
	col_index:		.word 0			# column count
	grid:			.space 900		# grid input
	new_grid:		.space 900		# next version of the grid
	
	.text
	
	
	
Main:	# prints grid_count_input and takes grid count

	jal take_row_and_column_count		# calls take row and column count function
	jal take_the_grid			# calls take the grid function
	jal fill_the_new_grid			# calls fill the new grid function
	jal explode_and_refill_grid		# calls explode and refill grid function
	
	# Exit the program
        li $v0, 10
        syscall


take_row_and_column_count:

	la $a0, grid_count_input		# prints enter grid count message
	li $v0, 4				# set system call string to print 
	syscall
	
        				# Read grid count input
        li $v0, 5           		# System call code for read_int
        syscall             		
        
        				# Store the grid count in memory
	sw $v0, grid_count
        li $v0, 1			# set system call to print int
        lw $a0, grid_count  		# Load the grid count from memory to print
        syscall
        
        li $v0, 4             			# Set system call number to print character
        la $a0, newline				# prints new line
        syscall

        					# prints col_count input and takes grid count
	la $a0, col_count_input			# prints enter col count message
	li $v0, 4				# set system call to print string
	syscall
	
        					# Read column count input
        li $v0, 5           			# System call code for read_int
        syscall             		
        
        					# Store the column count in memory
	sw $v0, col_count
        li $v0, 1
        lw $a0, col_count  			# Load the grid count from memory to print
        syscall
        
        li $v0, 4             		# Set system call number to print character
        la $a0, newline
        syscall
        jr $ra
        
take_the_grid:

        				# prints enter grid input and takes grid 
	la $a0, grid_input
	li $v0, 4			# set system call to print string
	syscall
	
        la $a0, grid        	# Load the address of the allocated space into $a0
        li $v0, 8           	# Set system call to read string
        li $a1, 900         	# Set the maximum number of characters to read
        syscall
        jr $ra

fill_the_new_grid:
	lw $t0, grid_count       # Load grid_count into $t0
        lw $t1, col_count        # Load col_count into $t1
        la $t2, new_grid         # Load the address of new_grid into $t2
        
        li $t3, 'O'              # Load the ASCII value of 'O' into $t3

    initialize_grid:
        beq $t0, $zero, end_init # If grid_count is zero, exit the loop

        li $t4, 0                # Initialize column index to 0

    fill_column:
        sb $t3, 0($t2)           # Store 'O' in the current element of new_grid
        addi $t2, $t2, 1         # Move to the next element in new_grid

        addi $t4, $t4, 1         # Increment column index

        bne $t4, $t1, fill_column # If column index is not equal to col_count, repeat the loop

        li $t4, 0                # Reset column index to 0

        addi $t0, $t0, -1        # Decrement grid_count
        j initialize_grid        # Repeat the loop
    
    end_init:
        
        jr $ra
        
explode_and_refill_grid:
	li $t0, 0		 	# set the element index 0
        la $t1, grid			# Load the address of grid into $t1
        la $t2, new_grid         	# Load the address of new_grid into $t2
        
	lw $t3, grid_count       	# Load grid_count into $t0
        lw $t4, col_count        	# Load col_count into $t1
        
        li $t5, 'O'              	# Load the ASCII value of 'O' into $t3
        li $t6, '.'		 	# load the ASCII value of '.' into $t4
        
       	li $t7, 1		# set the column index 1
       	li $t8, 0		# temp variable for further indexes
       	li $t9, 0		# another temp variable for loading indexes from arra

       check_next_position:
        	beq $t3, $zero, end_check 	# If grid_count is zero, exit the loop
	
		add $t8, $t0, $t1
	
		lb $t9, 0($t8)				# load the content of the current cell into $t9
		bne $t5, $t9, increment_index		# if the current cell isn't bomb, increment index and search for next cell
							# else, current cell is bomb
	cell_is_bomb:
		add $t8, $t0, $t2		# set $t8 to point the address of the cell
      		sb $t6, 0($t8)           	# Store '.' in the current element of new_grid
        
	is_cell_is_on_left_edge:
		beq $t7, 1, is_cell_is_on_right_edge	# if the column index is 1, it means its on the left edge and directly skip to next check
		addi $t8, $t0, -1		# if its not on the left edge, make '.' left of this cell
		add $t8, $t8, $t2		# set $t8 to point the address of the cell
		sb $t6, 0($t8)			# store '.' in the previous element 
	
	is_cell_is_on_right_edge: 
		beq $t7, $t4, is_cell_is_on_top_grid 	# if cell is on right edge, checks for if its on top grid 
		addi $t8, $t0, 1			# if its not on the right edge, make '.' right of this cell
		add $t8, $t8, $t2			# set $t8 to point the address of the cell
		sb $t6, 0($t8)				# store '.' in the next element

	is_cell_is_on_top_grid:
		blt $t0, $t4, is_cell_is_on_bottom_grid 	# if cell is on top grid, checks for if its on bottom grid 
		sub $t8, $t0, $t4		# if its not on the top grid, make the above cell '.'
		add $t8, $t8, $t2		# set $t8 to point the above element
		sb $t6, 0($t8)			# store '.' to above element
        
	is_cell_is_on_bottom_grid:
		beq $t3, $zero, increment_index 	# if cell is on bottom grid, increment index
		add $t8, $t0, $t4		# if its not, make the below cell '.'
		add $t8, $t8, $t2		# set $t8 to point the below cell
		sb $t6, 0($t8)			# store '.' to below cell
	
	increment_index:

		addi $t0, $t0, 1		# increment the string index
		addi $t7, $t7, 1		# increment the col index
		

		bgt $t7, $t4, reset_col_index_decrease_grid_count	# if col index is greater than column count, reset the column count
		j check_next_position	# jump to check next position
	
	reset_col_index_decrease_grid_count:
		li $t7, 1		# reset col index to 1
		addi $t3, $t3, -1	# decrement the grid count -1


	j check_next_position
	
    	end_check:
    		li $t0, 0			# input lines element index
    		li $t1, 0			# column index
    		la $t2, new_grid
    		
    		li $t3, 0			# temp variable for printing current element
    		li $t4, 0			# temp variable for pointing different elements in each turn
    		
    		lw $t5, grid_count       	# Load grid_count into $t0
        	lw $t6, col_count        	# Load col_count into $t1
        	
        	li $t7, 0			# row index
    		
		print_each_line:
			
			addi $t1, $t1, 1	# increment col index
			
    			add $t4, $t2, $t0	# point to next element
    			lb $t3, 0($t4)		# load the array element
    			
    			li $v0, 11
        		move $a0, $t3  		# print the element
        		syscall
        		
        		addi $t0, $t0, 1	# increment the arrays index after the print operation because its an address and it starts searching with 0, not 1
    			
    			bne $t1, $t6, print_each_line	# check if the element was the last element of that row
    			li $v0, 4             		# Set system call number to print character
        		la $a0, newline			# prints new line
        		syscall
        		
        		addi $t7, $t7, 1		# increment row index
        		li $t1, 0			# reset col index to 0
        		
        		bne $t7, $t5, print_each_line	# check if the last row is printed
        		jr $ra
        		
