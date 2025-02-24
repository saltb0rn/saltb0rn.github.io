(function(){
  let ptype;
  let re_index = /^(?:\/|\/index\.html(?:\/|\/.*)?)$/;
  let re_post = /^\/(?:.*)\.html(?:\/|\.*)?$/;
  // the behaviors of different type of pages are different.
  if (re_index.test(this.location.pathname)) {
    ptype = 'index';
  } else if (re_post.test(this.location.pathname)) {
    ptype = 'post';
  } else {
    ptype = 'other';
  }

  function setup_style_for_index() {
    console.log("The type of page is", ptype);
    let validation = document.querySelector(".validation");
    if (validation) {
      validation.style.display = "none";
    }
  }

  function setup_style_for_post() {
    console.log("The type of page is", ptype);
    let post_abstract = document.querySelector(".abstract");
    let toc = document.querySelector("#table-of-contents");

    if (toc) {
      post_abstract.parentNode.insertBefore(post_abstract, toc);
      
      const div = document.createElement("div");
      div.classList.add("table-bookmark");
      toc.appendChild(div);      

      div.addEventListener('click', function(event) {
        if (!toc.classList.contains("open")) {
          toc.classList.add('open');
        } else {
          toc.classList.remove('open');
        }
      });
    }
    // TODO: 加载页面时移除评论块,之后设计一个按钮,点击的时候再把comment_clone添加回去.
    // let comment = document.querySelector("#disqus_thread");
    // let comment_clone = comment.cloneNode(true);
    // if (comment) {
    //     comment.style.display = "none";
    //     comment.remove();
    //     console.log(comment_clone);
    // }
  }

  function setup_style_for_other() {
    console.log("The type of page is", ptype);
  }

  let page_style_map = {
    index: setup_style_for_index,
    post: setup_style_for_post,
    other: setup_style_for_other
  };

  function setup_style() {
    let func = page_style_map[ptype];
    if (func) {
      func();
    } else {
      console.log("No such type of page");
    }
  }

  // function log_error(err, url='') {
  //     if (!url) {
  //         let div = (window.document.querySelector("div.errlogs") ||
  //                    window.document.createElement('div'));
  //         if (!("errlogs" in div.classList))
  //         {
  //             window.document.appendChild(div);
  //             div.className = "errlogs";
  //         }
  //         let p = window.document.createElement('p');
  //         p.className = 'err';
  //         p.textContent = "message: "+ err.message + "\n" + "stack: " + er.stack + "\n";
  //         div.appendChild(p);
  //         return;
  //     }
  //     fetch(url, {
  //         method: "POST",
  //         mode: "no-cache",
  //         credentials: "same-origin",
  //         headers: {
  //             "Content-Type": "application/json; charset=utf-8"
  //         },
  //         redirect: "follow",
  //         referrer: "no-referrer",
  //         body: JSON.stringify(
  //             {
  //                 message: err.message,
  //                 stack: err.stack
  //             }
  //         )
  //     }).then(response => response.json());
  // }

  try {
    setup_style();
  } catch(err) {
    // log_error('');
  }

  if ('serviceWorker' in navigator) {
    // navigator.serviceWorker.register('/docs/sw.js');
    navigator.serviceWorker.getRegistrations()
      .then(regs => {
        for (let reg of regs) {
          if (reg.scope.indexOf(location.origin) >= 0) {
            reg.unregister();
          }
        }
      });
  }
})();
