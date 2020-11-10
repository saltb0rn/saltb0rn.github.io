(require 'json)
(require 'url)

(defstruct response headers body)

(defun url-open (url)
  "Return the response by requesting the url."
  (with-current-buffer (url-retrieve-synchronously url)
    (set-buffer-multibyte t)
    (decode-coding-region (point-min) (point-max) 'utf-8-dos)
    (goto-char (point-min))
    (re-search-forward "^$" nil 'move)
    (make-response :headers (buffer-substring-no-properties (point-min) (point))
                   :body (buffer-substring-no-properties (point) (point-max)))))

(defun data-filter (rsp)
  (with-temp-buffer
    (insert (response-body rsp))
    (let ((lst (cdr (dom-by-tag (libxml-parse-html-region (point-min) (point-max)) 'tr)))
          (baseUrl "https://gaokao.chsi.com.cn"))
      (mapcar
       (lambda (item)
         (let ((htable (make-hash-table)))
           (puthash
            "name"
            (if (dom-by-tag (car (dom-by-tag item 'td)) 'a)
                (string-trim (dom-text (dom-by-tag (car (dom-by-tag item 'td)) 'a)))
              (string-trim (dom-text (car (dom-by-tag item 'td)))))
            htable)

           (puthash
            "href"
            (concat baseUrl (dom-attr (dom-by-tag (car (dom-by-tag item 'td)) 'a) 'href))
            htable)

           (puthash
            "address"
            (string-trim (dom-text (cadr (dom-by-tag item 'td))))
            htable)

           (puthash
            "department"
            (string-trim (dom-text (caddr (dom-by-tag item 'td))))
            htable)

           (puthash
            "type"
            (string-trim (dom-text (cadddr (dom-by-tag item 'td))))
            htable)

           (puthash
            "level"
            (string-trim (dom-text (nth 4 (dom-by-tag item 'td))))
            htable)

           (puthash
            "lvl1-collage"
            (if (dom-by-tag (nth 5 (dom-by-tag item 'td)) 'i) t nil)
            htable)

           (puthash
             "lvl1-hight-school"
             (if (dom-by-tag (nth 6 (dom-by-tag item 'td)) 'i) t nil)
            htable)

           (puthash
            "graduate-school"
            (if (dom-by-tag (nth 7 (dom-by-tag item 'td)) 'i) t nil)
            htable)

           (puthash
            "score"
            (string-to-number (string-trim (dom-text (dom-by-tag (nth 8 (dom-by-tag item 'td)) 'a))))
            htable)

           (puthash
            "score-detail-id"
            (dom-attr (dom-by-tag (nth 8 (dom-by-tag item 'td)) 'a) 'data-id)
            htable)

           htable))
         lst))))

(defun main ()
  (let ((total 2800)
        (cur 0)
        dom-trees)
    (while (<= cur total)
      (let ((rsp (url-open (format "https://gaokao.chsi.com.cn/sch/search--ss-on,searchType-1,option-qg,start-%s.dhtml" cur))))
        (setq dom-trees (concatenate 'list dom-trees (data-filter rsp))))
      (setq cur (+ cur 20)))
    (write-to-file (json-encode dom-trees) "~/school-data.json")))

(main)
