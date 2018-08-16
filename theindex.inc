*** [[file:posts/2018/08/tornado-with-docker.html][用Docker打包Tornado项目]]
Docker是近几年一种新的容器技术,它的应用场景实在是太广泛了,除了在产品线上使用,我还见到过用来打包GUI应用的
[[http://fabiorehm.com/blog/2014/09/11/running-gui-apps-with-docker/][利用X11 socket与打包的Firefox通信]],还有利用同样原理对[[https://github.com/JAremko/docker-emacs][Emacs进行打包]]. 然而强大的工具都需要比较长的时间来学
习,其实我自己也没有用过多少次,用Docker的时候大多数都是用来搭个简单的API服务器用来测试,所以这里写一篇简单
的教程来示范如何简单的打包,如果标题所示,打包的项目是一个Tornado项目.

	
*** [[file:posts/2018/08/mysql-one-day-journay.html][MYSQL一日游]]
以前没怎么用过MYSQL,最近发现招聘要求好多都要求会MYSQL,读书的时候学的是微软家的SQL SERVER,出来工作用的是Postgresql
和大部份时间都是用SQLITE,偶尔还会用一下NOSQL,其中MongoDB用的最多.不过Django的ORM实在是太方便了,导致现在除了基本的
CRUD,增加/删除/修改表的SQL语句读忘的差不多了.而且虽然所每个数据库都在一定程度上遵守SQL标准,但是其实比对一下上面提到
的关系型数据库后你会发现,这简直就跟Lisp一样各种方言.所以我个人喜欢用ORM,这样就可以一份代码多个数据库使用.不过呢,懂
SQL是十分有必要的,而且ORM会有办不到的时候,当然最重要的还是概念,懂了概念后可以在以后不得不换数据库的时候知道怎么使用
文档.鉴于我自己的概念也不是太全,所以学习MYSQL的时候顺便写一篇笔记方便以后查阅,严格上来讲,这篇文章就是我从别的SQL数
据库转到MYSQL的心路里程和复习笔记.注意,本人用的版本是8.0.

	
*** [[file:posts/2018/07/sync-async-blocking-non-blocking.html][同步?异步?阻塞?非阻塞?到底有没有异步阻塞和异步非阻塞?]]
在网上关于synchronous(同步的), asynchronous(异步的), blocking(阻塞的)和non-blocking(非阻塞的)的概念有很多
不同说法,如果有人想要在网上开始了解这几个东西,怕是不能短时间内明白.因为实在是说法太多了.造成这个原因最主要是同一个术
语在不同上下文中有不同的意思,举个例子,演出的脚本跟计算机里面的脚本是一个意思吗?没错大部份人什么的时候连上下文都没有搞
清楚就开始解释了,所以今天就整理一下(可能会错,自己看看就好).

	
*** [[file:posts/2018/07/a-simple-websocket-echo-server.html][A Simple WebSocket Echo Server]]
It's time to learn WebSocket protocol by scratching a simple echo server after reading [[https://developer.mozilla.org/en-US/docs/Web/API/WebSockets_API/Writing_WebSocket_servers][Writing WebSocket Servers]].

	
*** [[file:posts/2018/07/macros.html][Macro in Racket]]
[[http://www.greghendershott.com/fear-of-macros/index.html][Fear of Macros]] is a good tutorial to get yourself into the world of macro, however, I get confused about
phase levels. To make it more clear, I read [[https://docs.racket-lang.org/guide/stx-phases.html?q=phase-level#%28tech._phase._level._1%29][Compile and Run-Time Phase]], [[https://docs.racket-lang.org/guide/phases.html?q=template%20phase%20level][General Phase Levels]] and[[https://beautifulracket.com/explainer/hygiene.html][ Hygiene]],
then did summaries for revisiting conveniently. Even so, I still get confused in some places. So, if you
have any problem or correction, please feel free to leave me your comments.

	
*** [[file:posts/2018/07/how-to-block-ip-addresses-from-countries.html][设置Nginx禁止某些地区IP的访问]]
闲来无事就去玩一下Nginx

	
*** [[file:posts/2018/07/regex.html][Regex]]
Well, if you always forget somethings, then you should take notes for you to remember them easily.
Regex, regular expression, is such a powerful tool that I always forget how to use it frequently.
It is powerful but not overwhelming, so if take it as your daily need, then there is no need to
take notes. For me, I would rather take notes in beginning, and now it is in it.

	
*** [[file:posts/2018/06/coroutines.html][Coroutines in Python]]
The first time I learned the word "Coroutines" in Python docs is about one year ago, I escaped from it
because it is not the easy thing to understand in a quick time and didn't have enough time to understand
it. However, I still studied it in spare time. Now, time to write down my understanding about "coroutines"
of Python. This article is about the concept of "coroutines", not a practical article, but I will give
you a resource to learn to how to use them.

	
*** [[file:posts/2018/06/continuation-passing-style.html][Continuation Passing Style]]
写一写自己对CPS的理解,个人经历有限,难免会有错误或者认识不全,所以请见谅.

	
*** [[file:posts/2018/06/about-rpc.html][网络编程笔记 RPC]]
最近复习了一下网络编程,顺便学习一下有所听闻的RPC.

	
*** [[file:posts/2018/06/about-python.html][About Python]]
Something about Python, including books and blogs

	
*** [[file:posts/2018/05/about-reading-code.html][关于阅读代码]]
一些关于最近阅读代码的想法

	
*** [[file:posts/2018/05/blog-with-emacs.html][Blog with Emacs and Org mode]]
I will show you the code that makes Emacs become a static site generator with Org mode

	
*** [[file:posts/2018/05/hello-world.html][Hello, world!]]
I describe why I blog with Emacs and Org-Mode

	
*** [[file:posts/2017/11/ssl-configuration-for-your-website.html][为你的网站配置SSL证书]]
	