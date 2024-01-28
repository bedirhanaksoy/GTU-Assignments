;; Load the lexer.lisp file
(load "lexer.lisp")

;; Function to parse an input string into an integer value
(defun valuef_parser (input)

  (loop for char across input
        for digit = (- (char-code char) (char-code #\0))
        for result = (if result (+ (* result 10) digit) digit)
        finally (return result)))

;; Function to perform summation of two fractions
(defun valuef_summation (fraction1 fraction2)

  (let* ((numerator1 (valuef_parser (subseq fraction1 0 (position #\b fraction1))))
         (denominator1 (valuef_parser (subseq fraction1 (1+ (position #\b fraction1)))))
         (numerator2 (valuef_parser (subseq fraction2 0 (position #\b fraction2))))
         (denominator2 (valuef_parser (subseq fraction2 (1+ (position #\b fraction2)))))
         (common-denominator (lcm denominator1 denominator2)))
    ;; Compute the sum and format the result
    (format nil "~db~d" (+ (* numerator1 (/ common-denominator denominator1))
                            (* numerator2 (/ common-denominator denominator2)))
            common-denominator)
  )
)

;; Function to perform subtraction of two fractions
(defun valuef_subtraction (fraction1 fraction2)
  (let* ((sign1 (if (string= (subseq fraction1 0 1) "-") -1 1))
         (sign2 (if (string= (subseq fraction2 0 1) "-") -1 1))
         (numerator1 (valuef_parser (subseq fraction1 (if (= sign1 -1) 1 0) (position #\b fraction1))))
         (denominator1 (valuef_parser (subseq fraction1 (1+ (position #\b fraction1)))))
         (numerator2 (valuef_parser (subseq fraction2 (if (= sign2 -1) 1 0) (position #\b fraction2))))
         (denominator2 (valuef_parser (subseq fraction2 (1+ (position #\b fraction2)))))
         (common-denominator (lcm denominator1 denominator2)))
    ;; Compute the difference and format the result
    (format nil "~db~d" (- (* sign1 numerator1 (/ common-denominator denominator1))
                            (* sign2 numerator2 (/ common-denominator denominator2)))
            common-denominator)
    )
)

;; Function to perform division of two fractions
(defun valuef_division (fraction1 fraction2)
  (let* ((numerator1 (valuef_parser (subseq fraction1 0 (position #\b fraction1))))
         (denominator1 (valuef_parser (subseq fraction1 (1+ (position #\b fraction1)))))
         (numerator2 (valuef_parser (subseq fraction2 0 (position #\b fraction2))))
         (denominator2 (valuef_parser (subseq fraction2 (1+ (position #\b fraction2)))))
         (result-numerator (* numerator1 denominator2))
         (result-denominator (* denominator1 numerator2)))
    ;; Compute the division and format the result
    (format nil "~db~d" result-numerator result-denominator)
  )
)

;; Function to perform multiplication of two fractions
(defun valuef_multiplication (fraction1 fraction2)

  (let* ((numerator1 (valuef_parser (subseq fraction1 0 (position #\b fraction1))))
         (denominator1 (valuef_parser (subseq fraction1 (1+ (position #\b fraction1)))))
         (numerator2 (valuef_parser (subseq fraction2 0 (position #\b fraction2))))
         (denominator2 (valuef_parser (subseq fraction2 (1+ (position #\b fraction2)))))
         (result-numerator (* numerator1 numerator2))
         (result-denominator (* denominator1 denominator2)))
    ;; Compute the product and format the result
    (format nil "~db~d" result-numerator result-denominator)
  )
)

;; Function to evaluate an expression, supporting basic operations
(defun expression_evaluation (expression)

  (destructuring-bind (operand arg1 arg2) expression
    (let ((value1 (if (listp arg1) (expression_evaluation arg1) arg1))
          (value2 (if (listp arg2) (expression_evaluation arg2) arg2)))
      ;; Choose the operation based on the operand and perform the calculation
      (case (intern operand)
        ((|OP_PLUS|) (valuef_summation value1 value2))
        ((|OP_MINUS|) (valuef_subtraction value1 value2))
        ((|OP_DIV|) (valuef_division value1 value2))
        ((|OP_MULT|) (valuef_multiplication value1 value2))
        (t (error "Unsupported operand"))
      )
    )
  )
)

;; Function to split a keyword list into operands and remaining_parts
(defun keyword_split (keyword_list)

  (labels ((splitter (remaining acc)
             (cond
               ((null remaining) (values (reverse acc) nil))
               ((string= (car remaining) "OP_OP")
                (multiple-value-bind (values remaining_parts)
                    (splitter (cdr remaining) nil)
                  (splitter remaining_parts (cons values acc))))
               ((string= (car remaining) "OP_CP")
                (values (reverse acc) (cdr remaining)))
               (t
                (splitter (cdr remaining) (cons (car remaining) acc))
               )
              )
            )
          )
    ;; Apply the splitter function to separate operands and remaining_parts
    (multiple-value-bind (operands remaining_parts) (splitter keyword_list nil)
      (values (cons (car operands) (cadr operands)) remaining_parts)
    )
  )
)

;; Main code block
(let* ((result (keyword_split tokenType))

       (expression (car result))
       (remaining_parts (cdr result))
      )
  ;; Evaluate the expression and print the result
  (format t "~a~%" (expression_evaluation expression))
)
