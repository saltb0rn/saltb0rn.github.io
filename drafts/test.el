;; This buffer is for text that is not saved, and for Lisp evaluation.
;; To create a file, visit it with C-x C-f and enter text in its buffer.

(defun get-lsb-release-info (item)
  "Available items: Distributor ID; Description, Release; Code name"
  (if (eq system-type 'gnu/linux)
      (with-temp-buffer
	(insert
	 (shell-command-to-string "lsb_release -a"))
	(goto-char (point-min))
	(save-match-data
	  (re-search-forward
	   (concat "^" item ":[[:space:]]*\\(.*\\)$")
	   nil t)
	  (match-string-no-properties 1)))
    (error "Your system is not Linux")))

;; (get-lsb-release-info "distributor id")

(password-read "密码: ")

;; process-send-string
;; https://stackoverflow.com/questions/22903910/emacs-call-process-as-sudo

(require 'etags)

(setq another-timer (run-at-time "60 sec" nil
				 (lambda () (message "hello"))))

;; timer-list
(require 'smtpmail)

(setq smtpmail-smtp-server "smtp-mail.outlook.com"
      ;; smtpmail-smtp-user "asche34@outlook.com"
      smtpmail-smtp-service 25
      smtpmail-stream-type 'starttls)

(with-temp-buffer
  (insert "TO: pythonicode34@outlook.com
Subject: [Notification] Test?
From: Saltb0rn <asche34@outlook.com>
--text follows this line--
Test")
;;  (buffer-string))
  (smtpmail-send-it))



