*** [[file:posts/2024/03/code-explains-for-fragment-shader-in-shadertoy.html?hash=18dafdc00b01e317893033c761dd815e][ShaderToy常见代码解释 (收录中)]]
在编程这一方面, 个人认同这一个观点: 要想实现某个东西最有效的办法是抄别人的代码, 并且要抄得明白.

不要看这句话看似很 =low=, 它里面其实有这么一些对应关系, "抄得明白"对应知道原理, "抄别人代码"对应实践.

对于 =ShaderToy= 也是一样的, 你想像那些前辈一样实现酷炫的效果, 就得脸皮厚一点去抄明白他们的代码, 大胆承认抄别人的代码.

并且要多抄, 抄到不用看就能随手写出来, 知道每一处代码的作用能按照自己的意愿进行修改, 到了这种地步就说明知识已经被内化了.

这篇笔记就是用来记录"明白"这一过程.

另外, 这里建议参考一下 [[https://thebookofshaders.com/][The Book of Shaders]] 这本书(截止目前为止还没写完).

	
*** [[file:posts/2022/03/dev-js-library-tutorial.html?hash=15536b0157a28f6b8c894959aa4c851d][JS库开发指南 (WIP)]]
最近公司给我分配了一个任务: 需要开发一个 3D 拓扑图的库.

以前一直都是写应用的, 没有写 JS 库的经验, 现在正好来了一个学习的机会.
# 记录开发一个Javascript库的过程

	
*** [[file:posts/2022/02/webgl-buffer-objects.html?hash=15af02dc2827eda5835634784caf24d3][Shader 编程自救指南]]
由于去年换了工作, 生活变得充实起来了, 这里的充实并非反话, 我在这段时间调整了心态和目标, 学习了一些新的知识;

为了学习游戏开发, 定制了新的学习目标, 包括音乐, 编剧, 使用 =Blender= 建模以及 =Godot= 的使用等等;

同时由于工作繁忙的原因, 图形学学习计划搁置了一年, 当时就停留在贴图映射的阶段.

另外搁置搁置还有一个原因, 那就是当时在学习贴图映射时所在的参考书有点不太易懂,

所以需要找一本更易读的书, 我找到了 [[https://gabrielgambetta.com/computer-graphics-from-scratch/][Computer Graphics from Scratch]], 当这本书当前还没完成编写, 因此决定等它出版了再继续学.

-----

PS: 现在是 2023 年 12 月, 我从今年的 6 月份开始就抽空读完这本书, 期间使用 =C= 语言按照书上的伪代码实践了一遍.

个人感觉等待这本书的完成是一个正确的选择, 它指导了我编写两个完整的渲染器, 简单易懂地解释了图形学里面一些较为复杂的算法.

我本人在读这本书之前就已经较为深入地学习了一些 [[../..//2020/06/graphics-geometric-transformation.html][数学细节]] 以及 [[../../2020/06/graphics-opengl-transformation.html][OpenGL的渲染管线]],

在跟着书本实践时特地找出这些知识和实践的对应之处, 学习效果非常地好.

这本书清晰了我在学习渲染管线时的一些迷糊之处, 而之前所学的数学细节以及渲染管线知识又很好地弥补了这本书在这方面的空缺.

现在回过头来看 =Shader= 程序如何运作时, 很多东西都豁然开朗了.

	
*** [[file:posts/2021/11/cake-cut.html?hash=89b204dbf435af8f53061ab2498d73dd][切饼问题]]
有一块圆形大饼,切 3 刀 *最多* 可以得到多少块?按照这个规律,切刀第 $n$ 刀时可以得到多少块?

(只考虑平面的情况)

	
*** [[file:posts/2021/06/things-about-c-development.html?hash=7fb86755187e1435f524f29cd4b8c6ce][关于使用C语言开发的那些事]]
*注意*, 看这篇笔记时请务必先学习 =x86= 汇编, 因为 =C= 代码会被编译成汇编,

只有学习了汇编你才能具体得看到 =C= 语言的内存管理模型, 知道程序是如何产生的, 是什么样的.

这篇文章是我在上手使用 =C= 语言开发时遇到了一些疑问而突发奇想写出来的,

这些疑问包括为什么要写头文件, 如何自己发布库文件, 如何发布项目代码, 如何构建项目等等.

相信很多初学者和我有同样的疑问, 很多 =C= 语言的书记都不会收录这些内容, 这也是情有可原的,

毕竟 =C= 语言的工具链比较复杂, 可选择范围太广, 不太可能单独介绍的.

我这篇笔记都是主要是围绕 =GNU= 提供的工具链进行的: =GNU C Compiler=, =GNU Binutils= 和 =GNU Autotools=,

以及 =Kitware= 提供的 =CMAKE=.

本文不是关于 =C= 语言教学的, 只是单纯的工具上手教学, 看之后保证你掌握大概用法, 以及如何查工具文档.

最后提一句, 这篇文章里面所有操作都是在 =Linux= 上完成的.

*UPDATED AT 2023/5/9*

本人发现了一本可以替代这篇笔记的书 "21st Century C, 2nd Edition",

这本书对于从汇编转 =C= 的新手来说是非常不错的实践参考, 并且内容详略得当.

这篇文章也有些书本上没有的内容, 虽然存在意义不太大了, 但笔记还是得保留下来.

	
*** [[file:posts/2021/03/understanding-about-animation-in-css.html?hash=4e4f1d18c3253d17c1d5565c780b3e09][理解CSS动画]]
这是一篇关于 =CSS animation= 属性的笔记.

虽然说 =MDN= 上有 =animation= 的文档,不过本人比较容易"异想天开",

不确定文档上的说明和我个人的理解是否一致,或者说有没有一些文档上没有说明的内容.

	
*** [[file:posts/2021/03/remainder-vs-modulo.html?hash=b4977a5d8a39be3a3626e3528bb9ae74][取余和取模的区别]]
说来惭愧,一直以来都没有真正明白取余(remainder operation)和取模(modulo operation)的区别,不是说他们计算的区别,而是用途上区别,

当然了,计算上的区别我也是不知道的,但是总有一两次会遇得到这其中所暴露的问题,所以今天就想办法理解它们的区别.

	
*** [[file:posts/2021/02/understanding-perspective-in-css.html?hash=3b47f43826cf443f14ea97d6d54f03eb][理解CSS中的透视]]
我以为在学习了透视投影以后就知道怎么使用CSS中的 =perspective= 属性了,然而我错了.

确实, =OpenGL= 透视和 =CSS= 中的透视概念上是一个东西,但在实际使用上两者还是有差别.

	
*** [[file:posts/2020/12/assembly.html?hash=f256d7c767c749e1dc1c56f3af4d1095][x86 汇编]]
这篇笔记的主要参考资料是 =Assembly Language Step-by-Step: Programming with Linux 3rd Edition=.

这本书的内容是围绕 =x86= 32 位来讲的, 我读这本书的时候 =x86= 64 位架构已经非常普遍了, 也就是说这本书已经有点过时了, 况且关于浮点数这块基本上没讲过.

不过, 在 =x86= 的 32 位和 64 位上写汇编的差别不大, 互联网的存在可以免去这点差异对你照成的困扰.

现在有两个问题: 为什么要学 =x86= 汇编(assembly)? 如何学汇编?

针对第一个问题, 作为一名业余计算机爱好者和从业人员可以说的是,

汇编可以让你了解到程序的本质是什么, 如何运行, 而程序本身又和操作系统打交道, 操作系统又和硬件打交道.

*越是了解一样事物其中的细节, 越是能够在事物出现异常时快速定位到问题所在, 从而解决问题*.

这些细节就是计算机世界的"物理法则", 在了解这些法则后, 当你创作自己的程序时, 你可以清楚地知道在实现某个目的有什么手段, 哪个手段更好以及什么不能做.

汇编归根到底是和硬件打交道的编程语言, 这里选择 =x86= 架构的汇编是在个人计算机中 =x86= 是主流架构.

针对第二个问题就是这篇笔记的重点了, 其实参考书的真正内容不多, 共 600 页左右,

导言部分就是书本的使用说明, 不管读的是不是这本书, 这种技术类书籍的导言是必看的;

第 1 章就是科普程序是怎么工作的, 如果你有一定的编程经验, 那么可以忽略这章节的剩余内容, 这章将近 12 页;

第 2 章就是关于悉数学进制的,如果你非常熟数学进制的话,请跳过这章,这章将近 30 页;

第 6 章节基本上就是推荐/介绍工具,如果你已经有自己顺手的编辑器或者有一定的 =Linux= 使用经验的话,

这章节基本可以速读一遍甚至是跳过,这里将近 50 页;

最后附录将近 70 页;

和我差不多基础的人可以跳过上面的内容, 那么剩下的内容对于我这样基础的人是比较重要的了,

第 3 章节是从硬件的层面介绍计算机是如何工作的, 相信大部分人都只处于计算机有 =CPU=, 内存(memory) 等硬件的理解上,

如果你也是这样的话就请不要跳过这章节;

第 4 章节依赖于第 3 章,整个章节是关于内存寻址(memory addressing),这章是这本书的灵魂;

第 5 章节是汇编的概览, 可以了解到计算机文件的本质, 以及如何开发一个汇编语言程序;

这三个章节给提供读者能够学好汇编的前提, 剩下的章节内容都是汇编的实操.

我写这篇笔记的目的在后期逐渐发生改变了, 从原来"想要了解"到"想把学到的知识真正的用在创作上",

为此加强了一下书中后期"从汇编转向 =C= 语言这一部分"的内容, 从而加入了 "=ELF= 文件解析以及连接器的工作细节" 这些参考书上没有的内容.

	
*** [[file:posts/2020/08/graphics-opengl-light-and-material.html?hash=aa67d4addc33ceec4c44974519a0998f][图形学-光和材质]]
在图形学中,决定一个物体是否逼真(realism),除了投影方法外,另外一个重要因素就是光照(lighting)了.

包括这几个方面: 光(light)影(shadow)的表现,不同材质(material)的物体如何反射(reflects)光线,以及当光线照射到半透明物体时该如何弯曲(bend)/衍射(diffracted).

这篇笔记主要是关于光和材质方面的概念,在学习以后你会知道如何编写 =Fragment Shader= 来控制光照效果,不过我们还是会从没有 =GLSL= 的 =OpenGL 1.X= 开始学习.

	
*** [[file:posts/2020/06/graphics-opengl-transformation.html?hash=b65a4607057c876d595fd676f4870624][图形学-OpenGL坐标变换]]
之前只讲了几何变换,也就是最简单的变换,本文主要透过 =OpenGL= 的各种坐标系来讲解图形学的渲染管线的坐标系是如何转换的,这对于理解 =OpenGL= 的渲染管线/渲染流水线(rendering pipeline, 我也不知道为什么会这么翻译)很有必要.

不过我不打算花重笔写渲染管线的内容,因为渲染管线会随着 =OpenGL= 的升级而改变, =OpenGL 1.X= 到 =OpenGL 2.X= 就经历一次重大改变: 固定管线被移除(fixed function pipepline),取而代之的是可编程管线(programmable pipeline),

=OpenGL Shader Language= (GLSL) 也是从这个版本出来的,其实也就是固定管线的一部分环节"放开权限"给开发人员编码,所以从 =OpenGL 1.X= 开始学习也是没问题的,

关于更多的本版变迁问题,可以在官方维基的这个[[https://www.khronos.org/opengl/wiki/History_of_OpenGL#OpenGL_1.0_.281992.29][页面]]看到,本文是按照 =1.X= 渲染管线来写的, =OpengL 1.X= 渲染管线的文章有很多,比如这里这[[http://www.songho.ca/opengl/gl_pipeline.html][一篇]],还是同一位作者,本文是参考了他的这篇文章: [[http://www.songho.ca/opengl/gl_transform.html][OpenGL Transformation]] 写的.

本文只会写渲染管线的两个环节: =Vertex Operation= 以及 =Primitive Assembly=,它们背后的数学原理,这是后面学习 =GLSL= 是必须的知识基础.

	
*** [[file:posts/2020/06/graphics-geometric-transformation.html?hash=6540ac38a3b19b7c4d5b8cc5977df64a][图形学-几何变换]]
几何变换(geometric transformation)是图形学里面的一个重要基础知识点,

所谓的几何变换可以它看做一个函数就是: 输入几何对象里面的所有点,输出一个新的几何对象.

举个例子,假如 $p$ 点在坐标系 $A$ 中的坐标是 $\left(x, y\right)$,假设现在坐标系 $B$ 是整个 $A$ + $p$ 逆时针旋转 $\theta$ 度后得到的,

同样 $p$ 也跟着 $A$ 的旋转到达 $p^{'}$ 这个位置, $p^{'}$ 在 $B$ 上也是 $\left(x, y\right)$, 但是 $p^{'}$ 在 $A$ 的坐标呢?

现在就是要求 $p^{'}$ 在 $A$ 上的坐标 $\left(x^{'}, y_{'}\right)$.

首先 $A$ 和 $B$ 分别是描述 $p$ 和 $p^{'}$ 自身的坐标系, $p$ 有 *可能* 会处于 $A$ 的原点位置, $p^{'}$ 和 $B$ 同理,

$A$ 和 $B$ 分别叫做 $p$ 和 $p^{'}$ 的物体坐标系(object coordinate system),每个物体都有自己的物体坐标系.

$p^{'}$ 实际上 就是 $p$ 相对于 $A$ 坐标系原点的移动结果,这种相对自己的物体坐标系进行的变换就是几何变换(geometric transformation).

[[../../../files/2d-rotation-pre.png]]

其实这里也可以看成是坐标变换(coordinate transformation),也就是从坐标系 $A$ 变成坐标系 $B$ 时, $p^{'}$ 在 $A$ 上的坐标是多少,

也就是改变了物体参照的坐标系,这里并不是说坐标变换就等于几何变换,只是这里是恰好可以看作一样而已,几何变换本质是在改变物体本身.

举个例子,一辆车在某个位置,现在想让车远离某一个人,那么有两种做法,一是把车开走,二是让人走开.

把人看作是车的物体坐标系的原点,车开走就是几何变换;车不动而人走开就是坐标系变换.

从人的角度来看,不管是哪种方式都可以实现车和人的距离拉远.坐标变换会在下一篇文章讲.

所以它们虽然本质不一样,但是它们的计算都基本都是 $Ax = y$ 这种形式.

回到主题,常见的几何变换包括对象的 *缩放,平移以及旋转*,这些都可以通过矩阵来进行描述.

而矩阵的含义就是等同于"映射/变换",所以在了解之前需要先了解一些线性代数的知识,我也不是这方面的专家,就不分享自己微不足道的学习经验了.

实际上如果单纯只是为了应用的话,记住结论就可以了,但是个人认为,如果真的打算与图形学打交道,那么只有理解了为什么才能愉快地与图形学相处,

否者会过得很痛苦.很多参考资料都是直接给出变换的结论,没有推导过程,或者有不完全的推导过程,所以我才下定注意写下自己思考.

在 [[https://betterexplained.com][Better Explained]] 的 [[https://betterexplained.com/articles/intuitive-understanding-of-eulers-formula][Intuitive Understanding Of Euler's Formula]] 上有一句话我非常喜欢:

=Formulas are not magical spells to be memorized: we must, must, must find an insight=,

而 =insight= 的其中一个解释是 =a deep intuitive understanding of a person or thing=,

所以这句话的意思是: 公式不是需要记忆的魔法咒语,我们要对公式有一个直观了解,包括公式是如何推导(reason)得到的,有什么意义,解决什么问题.

	
*** [[file:posts/2020/02/et-project-day-.html?hash=cb0123b7703c9bd0d13b552435a2a639][英语消灭计划-Day2]]
距离上一次英语消灭进行经是几个月前了,当时还是没有坚持下来,现在要开始重启这个计划了,还是不能小看"积累"的力量.

这次的阅读材料取自于 =VA-11 HALL-A:Cyberpunk Bartender Action=,游戏里的日期是 =Tue 13/12=.

	
*** [[file:posts/2019/12/linear-algebra-notes.html?hash=f16cee94383b82c3be8cba49269fd133][线性代数读书随笔 (部分内容需要严格验证)]]
"程序员的数学3线性代数"读书随笔

	
*** [[file:posts/2019/11/canvas-intro.html?hash=d7ed0af41591a9756520e60e15c301e1][Canvas入门而不入土]]
从 =Canvas= 的一些相关概念去入门,对 =Canvas= 的 =API= 有一个全局的理解.

这片文章并非是关于 =API= 的详细用法,而是让你用Canvas画图的时候会想有没有这种功能的API,然后自行去查阅文档.

可能有人会问: 不讲 =API= 的话这篇文章还有什么存在意义吗?

针对这个问题,我想那些有开发经验的人应该会理解,比如做 =WEB= 服务端开发,有时候被要求换一个框架,即便如此他们依然可以很快上手,

这是因为 =WEB= 的服务端开发是离不开 =Cookies,Request/Response-Headers, Request/Response-Body= 等等这些 =HTTP= 的知识以及概念,

不同框架 =API= 是肯定不一样的,有经验的开发人员要快速使用新的工具必然是从这些概念上去找对应的 =API= 的.

同样, =Canvas= 也是一样,谁知道以后 =Canvas= 的 =API= 会不会变呢,或许它的 =Canvas= 的某些概念会变,但是绝对比不上 =API= 的变化速度,

因为概念变了, =API= 也必然会变,但反过来就不一定,有可能只是单纯的为了少传两个参数而再封装一下,或者为了方便改变一下用法而已.

但是核心还是那一套概念.并不是说懂概念就是精通 =Canvas=,毕竟写代码是一件需要动手的事情,只是在动手之前对做的事情进行了解会让自己在之后的编码不会"迷茫".

这是为了防止秃头了还没学会,这也是我标题意思:单纯的入门,而不是乱敲一遍什么都不会然后入土.

当然我也会在相关话题下给出相关 =API= 链接,方便边读边动手.

	
*** [[file:posts/2019/11/web-components.html?hash=c81c0313e8367f8a1e1310806886cdb3][Web Components]]
前端组件化已经是大势所趋了,随着组件化的口号越来越响,在这种背景下诞生了一些用来实现组件化的开发工具,

在另外一方面,随着浏览器的现代化,WEB前端标准化也越来越重要,就连微软也意识到了这个趋势,在今年4月左右开始宣布新版的Edge开始使用 =chromium= 内核,

截至目前为止,Edge有两个分支在同时更新:旧版以及 =beta= 版,后者的内核就是 =chromium=, 这里是[[https://developer.microsoft.com/en-us/microsoft-edge/platform/status/shadowdom/][更新状态]].

在这个时代下,组件化也迎来了它的标准.

	
*** [[file:posts/2019/08/digital-video-file.html?hash=6c911c10f5fa2101fc3260ebf7b60b92][视频文件简单了解]]

因为临时的工作需要,要处理视频无法在 =ckplayer= 上面播放的问题,久违地使用了一下 =ffmpeg=.

在17年的时候就买了 =ffmpeg= 官网上推荐的 =ffmpeg basics= 来学习 =ffmpeg=,那个时候也是因为工作需求,

但是那个时候我还没有开始写 =blog=,所以这段时间会重新学习一边,顺便写些东西.

(从7.25日开始忙着下班玩火纹:风花雪月,已经偷懒了一段时间了,看来要把学习和锻炼像吃饭睡觉一样作为日常生活必选项).

复习 =ffmpeg= 之前先了解以下视频文件的一些基本概念,否则读 =ffmpeg basics= 会懵,我觉得这本书唯一的缺点就是没有先介绍视频文件,

对 =codec= , =format= 等基础概念的不理解会造成对 =ffmpeg= 的工作流程的不理解.

	
*** [[file:posts/2019/05/bash-eliminating-project.html?hash=c2371c6130e24e58dab33abb54ad7431][Bash消灭计划]]
用了两年多的 =Linux= 了,但是一直没有很系统地学习过 =Bash Scripting=,每次写的时候都是去翻文档,写完就忘,一直不能熟练的用它解决问题.

出现这种情况也有我自己的问题: 总想靠 =Python= 完成 =Shell= 的工作.然而事实上很多情况下用 =Python= 解决问题都不太方便,于是不得不重视起来.

这里我只会把几个比较不容易理解或重要的点写下来,目的一是为了节省边幅,去掉不重要的内容,方便以后查阅;二是为了个人偷懒.

	
*** [[file:posts/2019/05/et-project-day1.html?hash=8be760ab5c20cad8e0685ff3e747533a][英语消灭计划-Day1]]
从今天开始要拓展自己英语的词汇量了,起始之前很久就想拓展了,只不过没想到用博客这种形式来学习.

有一个准则,由于英语的一词多意的特征,所有笔记都会只介绍示例文本中的单词的当前用法.

关于单词的发音,由于本人用的是 =Merriam Webster= 词典,所以我是通过它使用的音标学习单词发音的,

官方音标指南在[[https://merriam-webster.com/assets/mw/static/pdf/help/guide-to-pronunciation.pdf][这里]],要注意它的是美式发音,这套音标比起其他音标好记易学很多,真是相见恨晚.

针对里面 =\ə\=, =\a\=, =\e\= 这几个比较容易记忆混乱的音标,我这里大概写一下个人学习的感悟:

在不考虑重读的情况下, =\ə\= 的读音和 [[https://www.merriam-webster.com/dictionary/uh][uh]] 这个拟声词的发音完全一致;

=\a\= 和 =\e\= 的读音十分类似,想听具体差别可以参考 [[https://www.merriam-webster.com/dictionary/bat][bat]] 和 [[https://www.merriam-webster.com/dictionary/bet][bet]] 这两个单词,两者读音差不多,口的运动模式也是差不多的,

区别在于前者口的动作幅度比后者的大.其实不追求太精确也是可以的,这三个是比较容易记混的,知道大概发音就行.

至于重读和弱读,就是前者的发音时间更长更清晰,后者则相反.

今天的示例文本来源于"八方旅人" 中 Primrose 的序章剧情. Primrose's Journal 1-1

	
*** [[file:posts/2019/04/data-transfer-unit.html?hash=434444e1f55bedb7c4bca46bf7cf528c][网络数据传输单位]]
今天在机核上看到一篇新闻: 韩国三大电信运营商从4月5日开始提供消费用5G通信服务.为了了解5G有多厉害,我决定了解一下数据传输单位.

	
*** [[file:posts/2019/03/about-audio-file-metadata.html?hash=6514460dc6c6304d1a9e838fe4ca7cfc][关于音频文件的元信息]]
在最近一次录入音频文件到数据库的时候突然想到一个问题: 该如何选择音频文件的专辑封面呢,该如何知道这首曲的艺术家是谁呢?

突然想到以前用 =Windows MediaPlayer= 打开一些本地音频的时候有专辑封面并且没找到这些封面放在哪里,然后就不知道为啥很自然的想到元信息(metadata).

这次就是来了解一下音频文件的元信息.

	
*** [[file:posts/2019/03/laziness-is-a-habit.html?hash=9d0f62f242d4be94594b3e6d45957245][自身经历谈懒惰]]
很多人或多或少会有所谓的懒癌或者拖延症,这里我主要结合自己的生活经历来思考懒惰是什么,为什么会懒惰以及怎么克服它.完全没有任何实验数据以及外部资料支撑,单纯是个人的感悟,也就是完全的民科之谈.

因为我本人也是身患懒癌,所以我才需要写下这些思考,同时也是为了找到"治疗"方法.

	
*** [[file:posts/2019/02/docker-compose-file.html?hash=fc6059b65dd767cce869080ac96e5b28][docker-compose.yml文件的编写]]
去年的时候写过一篇[[/posts/2018/08/tornado-with-docker.html][用Docker打包Tornado项目]]的文章,本来是打算很快补上后续文章的,不过那个时候学其他东西就忘记了.前一段时间家里的网络失常,笔记本的系统崩坏以及服务器的各种问题,为了以后可以快速恢复环境,因此要了解 =docker= 的更多用法,这文章就是给自己备忘的.

由于我本人也没有经常用 =Docker=,所以难免会有些遗漏,我自己也尽量避开这些点,给出相关连接.本文主要是讲述如何编写 =docker-compose.yml= 文件,从而使用 =docker-compose= 和 =docker stack deploy= 命令部署应用.

	
*** [[file:posts/2019/01/http-headers-tutorial-notes.html?hash=619e5f12aceb1861480621aad5854571][HTTP Headers 学习笔记]]
大概两年前粗略地读过一下 *HTTP权威指南* 这本书(不知道名字有没有记错),当时读起来感觉好难懂,现在想起来感觉就像读 =Reference= 一样,不过书的确是好书,不过做为教程就有点过于厚重了.

因为之前读 *HTTP权威指南* 的时候还有很多地方不太懂,所以最近打算要复习一下 =HTTP Headers= 的内容,正好发现 *MDN* 上面有这部分的教程,并且简单明了,于是打算针对这一块这个笔记.

说个题外话, *MDN* 真是一个关于 *WEB* 开发的很好的文档库,我说的 *WEB* 开发并非只针对前端或者后端,而是前后端的总和, *MDN* 的教程相比那些厚重的书可谓是好太多了,简单易懂,而且还免费,这里衷心感谢 *Mozilla* 以及开源社区的各位.

	
*** [[file:posts/2018/11/warframe-damage-cal.html?hash=06e4ac8f5862e54cb5776e9e7fb44724][Warframe伤害计算]]
4年前就玩过一段时间的 =Warframe=,后面由于固定队解散而 =AFK=,本来之前就有回归的意向加上最近登录了 =Nintendo Switch=,所以毫不犹豫地选择了回归,而且玩得还挺开心,这真的得感谢 =Panic Button=.

由于时间长没玩并且随着游戏的不断更新而导致机制变了好多,所以我要复习一下这个游戏伤害机制,复习资料我选择了 =Warframe= 的 =Fandom Wiki=, =fandom= 可以拆分为 =Fan= 和 =dom=,其中 =dom= 是 =kingdom= 里面的一个部分,有国度,国家的意思.

=fan= 当然就是粉丝的意思,所以这个维基资料就是粉丝整理的,并且都是经过玩家们验证的,准确性还是可以的.不过即便如此有空的话最好还是自己动手计算验证资料的准确,这是一个好习惯.

	
*** [[file:posts/2018/11/gimp-for-webfe-dev.html?hash=5dde4b7e323138c4e29a130f1597655f][前端人员的GIMP]]
虽然不太想承认,但是前端人员有时候的确会被叫做切图仔.其实孤身一人的前端人员的确需要会一点切图技能.

我自学时候都是在网上找设计稿来还原的,设计稿有了但是素材得自己动手,我就是因为这个问题才来写这篇文章得.

大部份前端人员都是在 =Windows= 或者 =MacOS= 上使用 =PhotoShop= 来处理这些工作,对于使用 =Linux= 的前端人员就行不通了.

这里我选择了 =GIMP= 做为 =PhotoShop= 的替代品.本人使用的 =GIMP= 版本是 *2.10*.

	
*** [[file:posts/2018/11/eopl-techniques-to-imp-interpreter.html?hash=66ed2ba4a4308706f7e83157515f7744][直译器的实现技术总结]]
主要是总结 =EOPL= 上的一些用于实现语言特性的技术,包括词法作用域,动态作用域,并发等等.

这篇笔记尽量不涉及实现的代码,除非代码比文字更容易描述,主要是思路方面以及几个关键疑问的 =why=,我也会把实践的[[https://github.com/saltb0rn/eopl3/tree/master/langs][代码]]放到 =GitHub= 上(,其实就是把书本配套的代码重构一遍而已,因为个人觉得原版代码有点乱).

还有个人建议不要使用书中展示的代码,因为存在一些BUG问题,并且没有得到更新,建议使用书本作者在Github上的repo: [[https://github.com/mwand/eopl3]],该 =repo= 会及时更新.

	
*** [[file:posts/2018/11/eopl-interpreter.html?hash=f7cc4e3a660d146d76866e7afeccab86][The Interpreter]]
之前写了一篇关于 =The Sllgen Parser= 的文章,那是我了解 =parser= 的笔记,主要是关于语言实现的前端部分,现在以后端部分为主.

之所以要写这两篇文章是因为之前读 =EOPL= 的时候太匆忙了,书本提供的代码只是过了一遍,没有形成一个写 =interpreter= 该有的思路.

这里我会继续以 =LET= 语言做为例子来 *理清楚编写 =interpreter= 思路*,不会涉及语言特性的实现问题和基础知识,不过我之后会单独写笔记进行总结.

这篇的文章的结构就是根据 =EOPL= 第三版的第三章中 *实现LET* 的内容结构进行重排(说是重排,实际是个人总结),之所以选这一个实践做为参考,那是因为整本书的实践都是基于这一套模式进行的.

重排是因为 =EOPL= 第三版的内容个人觉得零散和啰嗦,不形成自己的想法是不会有实质的收获,所以我就想,作者这么做是不是想让读者多花点时间思考呢?

除了总结,我这一次还会抽空把书上的例子按照这个思路重新实践一遍,这次绝对不含糊.并且总结语言特性实现方面的笔记,最后完成练习补全笔记.

	
*** [[file:posts/2018/11/eopl-sllgen.html?hash=23d2474a55f9807b0c3f028cac6fe017][The Sllgen Parser]]
=EOPL= 是一个本好书,所以我想完成上面的习题.不过主要内容只讲了如何写直译器, =parser= 部分只有在附录里面详细说明(可以理解,因为 =parser= 不是 =interpreter= 的一部分).

=Sllgen= 是 =eopl= 库提供的一个生成器,用来生成 =lexer= 和 =parser=.由于并没有在正文部分出现,那么我只能单独了解一下.

	
*** [[file:posts/2018/10/react-journay.html?hash=8331cb29fa38e5b2fae79ca85640cfd7][React学习之旅]]
因为各种原因我打算去做前端了,所以最近一直在学习,花了两到三天的事件调教出一份可以复用的 =Webpack= 配置(已经在 =GitHub= 上了),

然后又花了两天来学习 =React= 的基本用法,接下来就是恶补 =CSS= 的东西了,不过在此之前我要先写一写学习 =React= 时候的笔记.

这不是教程,只是笔记.官方文档已经很好了,想学的话自己看教程比较好.

	
*** [[file:posts/2018/09/design-patterns.html?hash=bbcb0e37fb2dd40bc9ba5d17f926a949][设计模式总结]]

参考 "Mastering Python Design Patterns",这本书的优点就是讲的通俗易懂,缺点就是模式不全(一共16种)和代码实例不够好(代码方面有些用了第三方库).

用 =Python= 实现了直译器模式以外的模式, 用 =Racket= 实现了原型模式和直译器模式以外的模式.

之所以没有实现直译器模式是因为直译器是一个大话题,不能三言两语讲清楚(主要是书上的例子跟 =EOPL3= 的讲解对比起来有点别扭),

至于 =Racket= 原型模式是因为我没有办法.

其中练习的时候参考了 [[https://www.cnblogs.com/Liqiongyu/p/5916710.html][二十三种设计模式及其python实现]] 这篇博客.之后会把剩下的6种补上(不算直译器模式,除去书中的 =MVC= 模式).

	
*** [[file:posts/2018/09/Racket-Guide-Notes.html?hash=714bc607e60062544e14dd68b67bec97][Racket Guide 笔记]]
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

	
*** [[file:posts/2018/09/web-frontend.html?hash=f87108427dee51f10862488a0c4b5ac6][前端学习笔记整理(持续更新)]]
读书的时候对前端热情不高所以敷衍过去了,等要用的时候才发现给自己留了坑,这就很憋屈了,于是静下心来了解一下,主要是了解前端的系统是怎么样的.

HTML,CSS和JavaScript是怎么协作,三者怎么学?

HTML元素这么多,能否分类或者怎么分类?

CSS同样也是有很多属性,如何掌握?能否分类或者怎么分类?

JavaScript又是怎么回事,语言部分要有哪些要点?APIs部分有没有系统而完善的文档?

这篇笔记主要是对所需要的概念进行理解并且整理,然后把日后开发所需的参考文档整理出来.

由于是笔记,所以会一之直更新.

P.S: 我接触过一些后端开发人员很抗拒前端,大部份认为,"前端都不涉及逻辑的,有什么意思?".这是一个错误的认识,以前的我不太清楚,但是看到现在的网站页面这么复杂还能说出这种话的人明显是没有经过思考的.

	
*** [[file:posts/2018/08/emacs-tips.html?hash=e739e9c22521e32ef393261393ceabf5][Emacs Tips(持续更新)]]
如果学一样东西不做知识管理的话,时间久了就会陷入Problem-Google-Solution-Forgotten 这样的循环中,记得读书时候有人说,看那个人做笔记那么

认真但还是考不好,真蠢.首先我个人不认为做笔记是一件蠢事,不过做笔记是需要技巧的,那个考不好的人可能是这里出了问题,或者只是他单纯的只是做笔

记而已.每当遇到问题去Google实际是一件很浪费时间的事情,为何不把内存里面的数据持久化下并且给它这个索引呢?记录的东西大部份都是很琐碎的,毕竟

是因为琐碎才要以这种形似记录下来.

P.S: 这文章做为我个人的知识管理方案之一会一直会更新.为什么不把每个话题分开写,那时因为记录的东西太琐碎了,不记录又不好,所以才写成一篇,不过分量大的话题会分开写,比如一些packages的用法.

	
*** [[file:posts/2018/08/redis.html?hash=e4aeef446db10ea8373d9a2ca4726f7e][Redis学习笔记]]
正如上一篇笔记所说的要做Redis的笔记.最好的参考书不是买来的,而是自己做的.这篇笔记的参考资料是The Little Redis book,
一本免费的书,你可以很容易地在互联网上找到它.并且我的整个学习过程都在Debian下完成,不会做关于在Windows上面操作的笔记.
并且涵盖可能不会太全面,这是可能是因为限于边幅,也就是涵盖东西太多不够精简,这种情况我会放出外部资源做补充;还可能是限于
我个人的水平而没涵盖到,不过我以后有空会补上的,毕竟给自己做参考书不是一朝一夕的事情.给自己debug应该是每天的任务.

	
*** [[file:posts/2018/08/distributed-computing-with-python.html?hash=7f574e781930805884f5c6f8e0e7d84f][Distributed Computing with Python的阅读笔记]]
最近要把一年以前没有完成的计划给完成掉,分布式就是其中一个,为了在一开始有个大概的了解,我决定选一本用指定编程语言并且
厚度不高的书来学习,这本Distributed Computing with Python就满足了我的需求,共154页,其中第5,6两章是关于使用AWS和
HPC来部署分布式应用,我跳过了这两章节.第2节是讲述异步编程(asynchronous/event-driven programming)的概念,这个快
速地过了一遍,第3章是关于如何使用Python来并行.第7章给了测试与调试的一些建议.第8章是最这本书来个大概总结,可以直接跳
过.重点是第4章,用了Celery,RabbitMQ和Redis来写例子示范如何编写分布式应用.当然这种关于大题材的薄书涵盖的点都不会很
全面的,但我倾向于那种能够在开始给个概念和示范的书,至于更深入的细节,以后再读相关的书,这里面所有的图片都是来自于这本
书.

	
*** [[file:posts/2018/08/tornado-with-docker.html?hash=03b9c1e75f96d5361a9ff427822bfb75][用Docker打包Tornado项目]]
Docker是近几年一种新的容器技术,它的应用场景实在是太广泛了,除了在产品线上使用,我还见到过用来打包GUI应用的
[[http://fabiorehm.com/blog/2014/09/11/running-gui-apps-with-docker/][利用X11 socket与打包的Firefox通信]],还有利用同样原理对[[https://github.com/JAremko/docker-emacs][Emacs进行打包]]. 然而强大的工具都需要比较长的时间来学
习,其实我自己也没有用过多少次,用Docker的时候大多数都是用来搭个简单的API服务器用来测试,所以这里写一篇简单
的教程来示范如何简单的打包,如果标题所示,打包的项目是一个Tornado项目.

	
*** [[file:posts/2018/08/mysql-one-day-journay.html?hash=996c74f71a5891673cf8cb7190a0b663][MYSQL一日游]]
以前没怎么用过MYSQL,最近发现招聘要求好多都要求会MYSQL,读书的时候学的是微软家的SQL SERVER,出来工作用的是Postgresql
和大部份时间都是用SQLITE,偶尔还会用一下NOSQL,其中MongoDB用的最多.不过Django的ORM实在是太方便了,导致现在除了基本的
CRUD,增加/删除/修改表的SQL语句读忘的差不多了.而且虽然所每个数据库都在一定程度上遵守SQL标准,但是其实比对一下上面提到
的关系型数据库后你会发现,这简直就跟Lisp一样各种方言.所以我个人喜欢用ORM,这样就可以一份代码多个数据库使用.不过呢,懂
SQL是十分有必要的,而且ORM会有办不到的时候,当然最重要的还是概念,懂了概念后可以在以后不得不换数据库的时候知道怎么使用
文档.鉴于我自己的概念也不是太全,所以学习MYSQL的时候顺便写一篇笔记方便以后查阅,严格上来讲,这篇文章就是我从别的SQL数
据库转到MYSQL的心路里程和复习笔记.注意,本人用的版本是8.0.

	
*** [[file:posts/2018/07/sync-async-blocking-non-blocking.html?hash=578ca0a43a5e72ccbbb8f0184ac9f636][同步?异步?阻塞?非阻塞?到底有没有异步阻塞和异步非阻塞?]]
在网上关于synchronous(同步的), asynchronous(异步的), blocking(阻塞的)和non-blocking(非阻塞的)的概念有很多
不同说法,如果有人想要在网上开始了解这几个东西,怕是不能短时间内明白.因为实在是说法太多了.造成这个原因最主要是同一个术
语在不同上下文中有不同的意思,举个例子,演出的脚本跟计算机里面的脚本是一个意思吗?没错大部份人什么的时候连上下文都没有搞
清楚就开始解释了,所以今天就整理一下(可能会错,自己看看就好).

	
*** [[file:posts/2018/07/a-simple-websocket-echo-server.html?hash=57123c1365998b8149f09c2f8c13e7a1][A Simple WebSocket Echo Server]]
It's time to learn WebSocket protocol by scratching a simple echo server after reading [[https://developer.mozilla.org/en-US/docs/Web/API/WebSockets_API/Writing_WebSocket_servers][Writing WebSocket Servers]].

	
*** [[file:posts/2018/07/macros.html?hash=ab873c2372536730bfe10ffdef57ffbe][Macro in Racket]]
[[http://www.greghendershott.com/fear-of-macros/index.html][Fear of Macros]] is a good tutorial to get yourself into the world of macro, however, I get confused about
phase levels. To make it more clear, I read [[https://docs.racket-lang.org/guide/stx-phases.html?q=phase-level#%28tech._phase._level._1%29][Compile and Run-Time Phase]], [[https://docs.racket-lang.org/guide/phases.html?q=template%20phase%20level][General Phase Levels]] and[[https://beautifulracket.com/explainer/hygiene.html][ Hygiene]],
then did summaries for revisiting conveniently. Even so, I still get confused in some places. So, if you
have any problem or correction, please feel free to leave me your comments.

	
*** [[file:posts/2018/07/how-to-block-ip-addresses-from-countries.html?hash=16f0718ff0d4c716f23d8a495c0a8beb][设置Nginx禁止某些地区IP的访问]]
闲来无事就去玩一下Nginx

	
*** [[file:posts/2018/07/regex.html?hash=27b1de209ff21eaf0b74be14454df093][Regex]]
Well, if you always forget somethings, then you should take notes for you to remember them easily.
Regex, regular expression, is such a powerful tool that I always forget how to use it frequently.
It is powerful but not overwhelming, so if take it as your daily need, then there is no need to
take notes. For me, I would rather take notes in beginning, and now it is in it.

	
*** [[file:posts/2018/06/coroutines.html?hash=cf966d9fa66c380c30a5516080c3b559][Coroutines in Python]]
The first time I learned the word "Coroutines" in Python docs is about one year ago, I escaped from it
because it is not the easy thing to understand in a quick time and didn't have enough time to understand
it. However, I still studied it in spare time. Now, time to write down my understanding about "coroutines"
of Python. This article is about the concept of "coroutines", not a practical article, but I will give
you a resource to learn to how to use them.

	
*** [[file:posts/2018/06/continuation-passing-style.html?hash=9ff371edf5b2ea6bdc67ed5f00ad2f48][Continuation Passing Style]]
写一写自己对 =CPS= 的理解,个人经历有限,难免会有错误或者认识不全,所以请见谅.

	
*** [[file:posts/2018/06/about-rpc.html?hash=b1f53a57f5dfd46a68e95f9536576992][网络编程笔记 RPC]]
最近复习了一下网络编程,顺便学习一下有所听闻的RPC.

	
*** [[file:posts/2018/06/about-python.html?hash=bc6fb9906ce5368e43582e3a952ea6ef][About Python]]
Something about Python, including books and blogs

	
*** [[file:posts/2018/05/about-reading-code.html?hash=404bac82c94674490a8de62f37ea2be5][关于阅读代码]]
一些关于最近阅读代码的想法

	
*** [[file:posts/2018/05/blog-with-emacs.html?hash=960f26726565a9d483db6271faeea695][Blog with Emacs and Org mode]]
I will show you the code that makes Emacs become a static site generator with Org mode

	
*** [[file:posts/2018/05/hello-world.html?hash=caace671380fadaad4dd61759a2f5e47][Hello, world!]]
I describe why I blog with Emacs and Org-Mode

	
*** [[file:posts/2017/11/ssl-configuration-for-your-website.html?hash=6ca8e97232d69f128464fbc3649c1196][为你的网站配置SSL证书]]
	