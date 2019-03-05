*** [[file:posts/2019/03/laziness-is-a-habit.html][自身经历谈懒惰]]
很多人或多或少会有所谓的懒癌或者拖延症,这里我主要结合自己的生活经历来思考懒惰是什么,为什么会懒惰以及怎么克服它.完全没有任何实验数据以及外部资料支撑,单纯是个人的感悟,也就是完全的民科之谈.

因为我本人也是身患懒癌,所以我才需要写下这些思考,同时也是为了找到"治疗"方法.

	
*** [[file:posts/2019/02/docker-compose-file.html][docker-compose.yml文件的编写]]
去年的时候写过一篇[[/posts/2018/08/tornado-with-docker.html][用Docker打包Tornado项目]]的文章,本来是打算很快补上后续文章的,不过那个时候学其他东西就忘记了.前一段时间家里的网络失常,笔记本的系统崩坏以及服务器的各种问题,为了以后可以快速恢复环境,因此要了解 =docker= 的更多用法,这文章就是给自己备忘的.

由于我本人也没有经常用 =Docker=,所以难免会有些遗漏,我自己也尽量避开这些点,给出相关连接.本文主要是讲述如何编写 =docker-compose.yml= 文件,从而使用 =docker-compose= 和 =docker stack deploy= 命令部署应用.

	
*** [[file:posts/2019/01/http-headers-tutorial-notes.html][HTTP Headers 学习笔记]]
大概两年前粗略地读过一下 *HTTP权威指南* 这本书(不知道名字有没有记错),当时读起来感觉好难懂,现在想起来感觉就像读 =Reference= 一样,不过书的确是好书,不过做为教程就有点过于厚重了.

因为之前读 *HTTP权威指南* 的时候还有很多地方不太懂,所以最近打算要复习一下 =HTTP Headers= 的内容,正好发现 *MDN* 上面有这部分的教程,并且简单明了,于是打算针对这一块这个笔记.

说个题外话, *MDN* 真是一个关于 *WEB* 开发的很好的文档库,我说的 *WEB* 开发并非只针对前端或者后端,而是前后端的总和, *MDN* 的教程相比那些厚重的书可谓是好太多了,简单易懂,而且还免费,这里衷心感谢 *Mozilla* 以及开源社区的各位.

	
*** [[file:posts/2018/11/warframe-damage-cal.html][Warframe伤害计算]]
4年前就玩过一段时间的 =Warframe=,后面由于固定队解散而 =AFK=,本来之前就有回归的意向加上最近登录了 =Nintendo Switch=,所以毫不犹豫地选择了回归,而且玩得还挺开心,这真的得感谢 =Panic Button=.

由于时间长没玩并且随着游戏的不断更新而导致机制变了好多,所以我要复习一下这个游戏伤害机制,复习资料我选择了 =Warframe= 的 =Fandom Wiki=, =fandom= 可以拆分为 =Fan= 和 =dom=,其中 =dom= 是 =kingdom= 里面的一个部分,有国度,国家的意思.

=fan= 当然就是粉丝的意思,所以这个维基资料就是粉丝整理的,并且都是经过玩家们验证的,准确性还是可以的.不过即便如此有空的话最好还是自己动手计算验证资料的准确,这是一个好习惯.

	
*** [[file:posts/2018/11/gimp-for-webfe-dev.html][前端人员的GIMP]]
虽然不太想承认,但是前端人员有时候的确会被叫做切图仔.其实孤身一人的前端人员的确需要会一点切图技能.

我自学时候都是在网上找设计稿来还原的,设计稿有了但是素材得自己动手,我就是因为这个问题才来写这篇文章得.

大部份前端人员都是在 =Windows= 或者 =MacOS= 上使用 =PhotoShop= 来处理这些工作,对于使用 =Linux= 的前端人员就行不通了.

这里我选择了 =GIMP= 做为 =PhotoShop= 的替代品.本人使用的 =GIMP= 版本是 *2.10*.

	
*** [[file:posts/2018/11/eopl-techniques-to-imp-interpreter.html][直译器的实现技术总结]]
主要是总结 =EOPL= 上的一些用于实现语言特性的技术,包括词法作用域,动态作用域,并发等等.

这篇笔记尽量不涉及实现的代码,除非代码比文字更容易描述,主要是思路方面以及几个关键疑问的 =why=,我也会把实践的[[https://github.com/saltb0rn/eopl3/tree/master/langs][代码]]放到 =GitHub= 上(,其实就是把书本配套的代码重构一遍而已,因为个人觉得原版代码有点乱).

	
*** [[file:posts/2018/11/eopl-interpreter.html][The Interpreter]]
之前写了一篇关于 =The Sllgen Parser= 的文章,那是我了解 =parser= 的笔记,主要是关于语言实现的前端部分,现在以后端部分为主.

之所以要写这两篇文章是因为之前读 =EOPL= 的时候太匆忙了,书本提供的代码只是过了一遍,没有形成一个写 =interpreter= 该有的思路.

这里我会继续以 =LET= 语言做为例子来 *理清楚编写 =interpreter= 思路*,不会涉及语言特性的实现问题和基础知识,不过我之后会单独写笔记进行总结.

这篇的文章的结构就是根据 =EOPL= 第三版的第三章中 *实现LET* 的内容结构进行重排(说是重排,实际是个人总结),之所以选这一个实践做为参考,那是因为整本书的实践都是基于这一套模式进行的.

重排是因为 =EOPL= 第三版的内容个人觉得零散和啰嗦,不形成自己的想法是不会有实质的收获,所以我就想,作者这么做是不是想让读者多花点时间思考呢?

除了总结,我这一次还会抽空把书上的例子按照这个思路重新实践一遍,这次绝对不含糊.并且总结语言特性实现方面的笔记,最后完成练习补全笔记.

	
*** [[file:posts/2018/11/eopl-sllgen.html][The Sllgen Parser]]
=EOPL= 是一个本好书,所以我想完成上面的习题.不过主要内容只讲了如何写直译器, =parser= 部分只有在附录里面详细说明(可以理解,因为 =parser= 不是 =interpreter= 的一部分).

=Sllgen= 是 =eopl= 库提供的一个生成器,用来生成 =lexer= 和 =parser=.由于并没有在正文部分出现,那么我只能单独了解一下.

	
*** [[file:posts/2018/10/react-journay.html][React学习之旅]]
因为各种原因我打算去做前端了,所以最近一直在学习,花了两到三天的事件调教出一份可以复用的 =Webpack= 配置(已经在 =GitHub= 上了),

然后又花了两天来学习 =React= 的基本用法,接下来就是恶补 =CSS= 的东西了,不过在此之前我要先写一写学习 =React= 时候的笔记.

这不是教程,只是笔记.官方文档已经很好了,想学的话自己看教程比较好.

	
*** [[file:posts/2018/09/design-patterns.html][设计模式总结]]

参考 "Mastering Python Design Patterns",这本书的优点就是讲的通俗易懂,缺点就是模式不全(一共16种)和代码实例不够好(代码方面有些用了第三方库).

用 =Python= 实现了直译器模式以外的模式, 用 =Racket= 实现了原型模式和直译器模式以外的模式.

之所以没有实现直译器模式是因为直译器是一个大话题,不能三言两语讲清楚(主要是书上的例子跟 =EOPL3= 的讲解对比起来有点别扭),

至于 =Racket= 原型模式是因为我没有办法.

其中练习的时候参考了 [[https://www.cnblogs.com/Liqiongyu/p/5916710.html][二十三种设计模式及其python实现]] 这篇博客.之后会把剩下的6种补上(不算直译器模式,除去书中的 =MVC= 模式).

	
*** [[file:posts/2018/09/Racket-Guide-Notes.html][Racket Guide 笔记]]
这篇笔记的最早是从 =2018-9-8= 开始写的.

接触 =Racket= 有一段时间了,比 =Emacs Lisp= 要晚一点,一直没有很认真的读过官方 =Racket Guide= 手册.

几个月前读了 =EOPL= 这本书之后就很喜欢这门语言了,不过空余时间不多,所以只能用碎片时间来读,顺便写写笔记.

虽然"抄文档"这方式学语言"很蠢",但是十分有效,因为文档的一些描述可能不太符合自己,这种时候就需要自己把感想和重点记录下来,这样读完一遍会大有收获.

其实文档还有 =Racket Reference= 的,不过个人觉得如果是概念的话还是看 =Guide= 比较好, =Reference= 主要偏向于 =APIs= 文档.

我主要是整理文档上的 =working examples= 和写一些自己的 =working examples= 和感想,为了理解做笔记会涉及一些其它语言的特性来做类比,不涵盖所有章节,只写比较重要的章节.

还有就是有一部分文档的内容不太明白,比如语法污染这种,之后我会花时间去了解.

个人不太推荐看我这篇笔记,我主要是给自己做备忘和理解的,会有很多笔误或者理解错误.

但是也要知道一件事,官方文档的错误也有不少,有些例子是不能正常运行的,比如第14章的关于给单元添加约束是有问题的,所以自己读官方文档的人要注意了.

还有读完 =Guide= 以后的时间里面都是 =Reference= 的主场了, =Reference= 有很多 =Guide= 没有的东西等着去挖掘,比如新的数据类型,新的细节, =Guide= 只是个开始.

	
*** [[file:posts/2018/09/web-frontend.html][前端学习笔记整理(持续更新)]]
读书的时候对前端热情不高所以敷衍过去了,等要用的时候才发现给自己留了坑,这就很憋屈了,于是静下心来了解一下,主要是了解前端的系统是怎么样的.

HTML,CSS和JavaScript是怎么协作,三者怎么学?

HTML元素这么多,能否分类或者怎么分类?

CSS同样也是有很多属性,如何掌握?能否分类或者怎么分类?

JavaScript又是怎么回事,语言部分要有哪些要点?APIs部分有没有系统而完善的文档?

这篇笔记主要是对所需要的概念进行理解并且整理,然后把日后开发所需的参考文档整理出来.

由于是笔记,所以会一之直更新.

P.S: 我接触过一些后端开发人员很抗拒前端,大部份认为,"前端都不涉及逻辑的,有什么意思?".这是一个错误的认识,以前的我不太清楚,但是看到现在的网站页面这么复杂还能说出这种话的人明显是没有经过思考的.

	
*** [[file:posts/2018/08/emacs-tips.html][Emacs Tips(持续更新)]]
如果学一样东西不做知识管理的话,时间久了就会陷入Problem-Google-Solution-Forgotten这样的循环中,记得读书时候有人说,看那个人做笔记那么

认真但还是考不好,真蠢.首先我个人不认为做笔记是一件蠢事,不过做笔记是需要技巧的,那个考不好的人可能是这里出了问题,或者只是他单纯的只是做笔

记而已.每当遇到问题去Google实际是一件很浪费时间的事情,为何不把内存里面的数据持久化下并且给它这个索引呢?记录的东西大部份都是很琐碎的,毕竟

是因为琐碎才要以这种形似记录下来.

P.S: 这文章做为我个人的知识管理方案之一会一直会更新.为什么不把每个话题分开写,那时因为记录的东西太琐碎了,不记录又不好,所以才写成一篇,不过分量大的话题会分开写,比如一些packages的用法.

	
*** [[file:posts/2018/08/redis.html][Redis学习笔记]]
正如上一篇笔记所说的要做Redis的笔记.最好的参考书不是买来的,而是自己做的.这篇笔记的参考资料是The Little Redis book,
一本免费的书,你可以很容易地在互联网上找到它.并且我的整个学习过程都在Debian下完成,不会做关于在Windows上面操作的笔记.
并且涵盖可能不会太全面,这是可能是因为限于边幅,也就是涵盖东西太多不够精简,这种情况我会放出外部资源做补充;还可能是限于
我个人的水平而没涵盖到,不过我以后有空会补上的,毕竟给自己做参考书不是一朝一夕的事情.给自己debug应该是每天的任务.

	
*** [[file:posts/2018/08/distributed-computing-with-python.html][Distributed Computing with Python的阅读笔记]]
最近要把一年以前没有完成的计划给完成掉,分布式就是其中一个,为了在一开始有个大概的了解,我决定选一本用指定编程语言并且
厚度不高的书来学习,这本Distributed Computing with Python就满足了我的需求,共154页,其中第5,6两章是关于使用AWS和
HPC来部署分布式应用,我跳过了这两章节.第2节是讲述异步编程(asynchronous/event-driven programming)的概念,这个快
速地过了一遍,第3章是关于如何使用Python来并行.第7章给了测试与调试的一些建议.第8章是最这本书来个大概总结,可以直接跳
过.重点是第4章,用了Celery,RabbitMQ和Redis来写例子示范如何编写分布式应用.当然这种关于大题材的薄书涵盖的点都不会很
全面的,但我倾向于那种能够在开始给个概念和示范的书,至于更深入的细节,以后再读相关的书,这里面所有的图片都是来自于这本
书.

	
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
写一写自己对 =CPS= 的理解,个人经历有限,难免会有错误或者认识不全,所以请见谅.

	
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
	