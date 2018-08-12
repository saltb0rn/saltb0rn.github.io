;; This buffer is for text that is not saved, and for Lisp evaluation.
;; To create a file, visit it with C-x C-f and enter text in its buffer.

(defun foo () (interactive) (insert "hello"))
(defadvice foo (after foo-after activate) (insert " world!\n"))
(ad-unadvise 'foo)
(defun insert-after ()
  (interactive)
  (insert " world!\n"))

(advice-add 'insert-after :before 'foo)

;(insert-after)

(defun my-tracing-function (val)
  (message (format "ARG is %s" val)))

(defun traced-function (val)
  (+ val 1)
  (message (format "%s arg" (+ val 1))))

(add-function :around (local 'traced-function) #'my-tracing-function)

(my-tracing-function 1)

(traced-function 1)

(my-tracing-function 1)

