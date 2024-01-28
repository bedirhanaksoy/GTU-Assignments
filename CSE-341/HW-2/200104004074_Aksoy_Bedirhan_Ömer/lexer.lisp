(setq KeyWordList (list "and" "or" "not" "equal" "less" "nil" "list" "append" "concat" "set" "def" "for" "if" "exit" "load" "display" "true" "false"))
(setq KW (list "KW_AND" "KW_OR" "KW_NOT" "KW_EQUAL" "KW_LESS" "KW_NIL" "KW_LIST" "KW_APPEND" "KW_CONCAT" "KW_SET" "KW_DEF" "KW_FOR" "KW_IF" "KW_EXIT" "KW_LOAD" "KW_DISPLAY" "KW_TRUE" "KW_FALSE"))
(setq OperatorList (list "+" "-" "/" "*" "(" ")" ","))
(setq OP (list "OP_PLUS" "OP_MINUS" "OP_DIV" "OP_MULT" "OP_OP" "OP_CP" "OP_COMMA"))
; keyword and operator definitions

(setq SpaceElement (list "\n" "\t" " "))
(setq Comment ";")
; space characters and comment sign definitions

(defvar completed 0)
; completed flag statement 


; main function which reads lines from file 
(defun gppinterpreter (filename)
  (with-open-file (file filename :direction :input)
    (loop for line = (read-line file nil)
      while line
      do (parse-string line)
    )
  )
)

; parses string into words in order to tokens and spaces
(defun parse-string (input-string)
  (let ((start 0)
        (end 0)
        (len (length input-string))          
        (splitted-string (parse-helper input-string)))
                                       
    (loop
      for start = 0 then (1+ end)
      for end = (position #\Space splitted-string :start start)
      for word = (subseq splitted-string start end)
      until (null end)
      do (progn
        (if (>= len 2)      ; if its comment line, ommits the rest of it
          (if (string= (subseq splitted-string 1 2) Comment)
          (progn  (format t "COMMENT~%")  (return t))
          )
        )
        (parse-word word)   ; if not, it goes to parse the word
      )
    )
  )
)

; checks the word looking char by char
(defun parse-word (word)
	(let ((len (length word)) (wordPiece) (j 0) (res) (temp) (id 0))
        (setq completed 0)
		(loop for i from 1 to len
			do    
            ; if current word piece is classified correctly, passes new piece
            (if (= completed 1) (setq completed 0) )
            (setq wordPiece (subseq word j i))
            
            ; comment check again
            (if (and (equal completed 0) (>= len 2) (string= (subseq word 0 1) Comment)) 
              (if (string= (subseq word 1 2) Comment)
                  (progn  (format t "COMMENT~%")  (setq completed 2))
              )
            )

            ; checks its valid type or not
            (setq isValidTypeOrID (define-and-print-type word wordPiece i j len ))
            (if (and (equal completed 0) (not (equal isValidTypeOrID nil)) )
                (progn 
                    (if (equal isValidTypeOrID 1)
                        (setq j i)
                    )
                    (setq completed 1)
                )
            )
            
            ; if its comment, returns
            (if (= completed 2) (return completed))
		)
		completed			
	)
)

  ; defines and prints type
(defun define-and-print-type (word wordPiece i j len)
        ;searchs keyword list, operator list and space lists. if its exists, it prints the related keyword
  (let ((kw-index (position wordPiece KeyWordList :test #'string=))
        (op-index (position wordPiece OperatorList :test #'string=))
        (space-index (position wordPiece SpaceElement :test #'string=))
        (done 0)
       )
    ; if its in keyword list, it prints related keyword
    (when kw-index
      (format t "~a~%" (nth kw-index KW))
      (setf done 1)
    )
    ;if its in operator list, it prints related operator
    (when op-index
      (format t "~a~%" (nth op-index OP))
      (setf done 1)
    )
    ; it its none of the above, it can be valuef, identifier or an error
    (if(and (equal done 0) (equal i len)) 
      (progn 
        ;checks its a valid VALUEF or not 
        (if(is-valuef wordPiece)
          ; if it is, it prints VALUEF 
          (format t "VALUEF ~%")      
            ; if its not a VALUEF, it checks if its a valid IDENTIFIER
            (if(check-input wordPiece)(format t "IDENTIFIER ~%" )(progn(format t "~a cannot be tokenized ~%"wordPiece)(exit))) )
        (setf done 1)      
      )
    )
    done
  )
)

; checks if its a valid VALUEF
(defun is-valuef (input-string)
  "Check if the input is unsigned fraction."
  (let* ((b-index (position #\b input-string))
         (before-b-index (if b-index
                       (subseq input-string 0 b-index)"")
         )
         (after-b-index (if b-index
                      (subseq input-string (1+ b-index)) input-string)
         )
        )
    (and (not (zerop (length before-b-index))) 
         (not (zerop (length after-b-index)))  
         (every #'digit-char-p before-b-index)
         (every #'digit-char-p after-b-index)
    )
  )
)

; it puts spaces before and after paranthesis and commas
(defun parse-helper (input)
  (let* ((lines (concatenate 'string input " "))
         (separators '(#\( #\) #\,))
         (result "")
         (i 0)
         (len (length lines)))

    (loop while (< i len) do
      (let ((char (char lines i)))
        (if (find char separators :test #'char=)
            (setq result (concatenate 'string result " " (string char) " "))
            (setq result (concatenate 'string result (string char)))
        )
        (setq i (+ i 1))
      )
    )
    result
  )
)

; it checks wether the input is a valid IDENTIFIER or not
(defun check-input (input)
  (if (or (string= "" input)  
          (and (>= (char-code (char input 0)) (char-code #\0))
               (<= (char-code (char input 0)) (char-code #\9)))
          (loop for char across input
                thereis (not (alphanumericp char))
          )
      )  
      nil
      t
  )
)

; calls gppinterpreter with "not.txt" file
(gppinterpreter "test-input.txt")