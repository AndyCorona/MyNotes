# 第二章 Git 基础

### 2.1 创建 Git 仓库

在项目的工作目录下，执行 ```git init```命令，该项目就开始用 Git 管理，Git 会在创建 .git 目录，所有 Git 需要的数据和资源都存放在 .git 目录里，包括暂存区和本地仓库。
初始化后，项目中所有文件为未跟踪，使用 git add 命令告诉 Git 要跟踪哪些文件。

### 2.2 克隆仓库

对于已经使用 Git 管理的项目，使用 git clone [url] 命令克隆其仓库。初次克隆仓库时，工作目录中的所有文件都是已跟踪文件，状态为未修改。
```dos
git clone git://github.com/schacon/grit.git 
git clone git://github.com/schacon/grit.git myproject
```
第一条 clone 命令使用 git:// 协议克隆 Ruby 语言的 Git 代码仓库 Grit，并在当前目录下创建一个名为 grit 的目录。第二条命名重新指定项目目录名为 myproject 替代原来的 grit。

### 2.3 对仓库的操作

工作目录下的所有文件只有两种状态：已跟踪和未跟踪。已跟踪的文件是已经使用版本控制的文件，它们在 Git 中三种状态。未跟踪的文件是未使用版本控制的文件，Git 会进行提醒。
修改已跟踪的文件后，文件状态从已提交变更为已修改。把文件放入暂存区后，文件状态从已修改变更为已暂存。提交暂存区中的文件后，文件状态从已暂存变更为已提交。已跟踪的文件在三个状态循环往复（如图一）。

![三种状态](E:\BaiduNetdiskDownload\Typora\Git\02Git基础.assets\QQ截图20210817221650.png)

图一、已跟踪文件在 Git 中的三种状态

#### 2.3.1 查看项目的状态

git status
untracked files 一栏下列出项目目录下所有未追踪的文件和目录

```dos
No commits yet

Untracked files: 
  (use "git add <file>..." to include in what will be committed)
        1..txt
        2..txt
        files/

nothing added to commit but untracked files present (use "git add" to track)
```

#### 2.3.2 跟踪新文件

git add filename
```dos
git add 1.txt #追踪1.txt 文件
```
```dos
git status
On branch master

No commits yet

Changes to be committed:
  (use "git rm --cached <file>..." to unstage)
        new file:   1.txt

Untracked files:
  (use "git add <file>..." to include in what will be committed)
        2.txt
        files/
```

#### 2.3.3 暂存已修改文件

修改工作目录下的文件后，查看项目状态。Changes not staged for commit 一栏下列出工作目录下所有已修改但未提交到暂存区的文件和目录。
```dos
On branch master

No commits yet

Changes to be committed:
  (use "git rm --cached <file>..." to unstage)
        new file:   1.txt

Changes not staged for commit:
  (use "git add <file>..." to update what will be committed)
  (use "git restore <file>..." to discard changes in working directory)
        modified:   1.txt


```
git add filename 可将修改后的文件存入暂存区，会覆盖相同的文件。
```dos
git add 1.txt
```
```dos
On branch master

No commits yet

Changes to be committed:
  (use "git rm --cached <file>..." to unstage)
        new file:   1.txt
```

#### 2.3.4 忽略某些文件
在 .gitignore 文件下配置的文件会被 Git 忽略，即使查看项目状态时，也不会出现在未跟踪文件列表中。
使用标准的 glob 模式匹配，glob 用于匹配文件路径，和正则类似但语法有些差异。

| 通配符 | 描述                           | 模式示例 | 匹配示例          |
| ------ | ------------------------------ | -------- | ----------------- |
| \*     | 匹配 0 或 多个字符，包含空串   | app*     | app, apps, append |
| ?      | 匹配一个字符                   | ?at      | cat, bat          |
| [abc]  | 匹配括号内字符集中的单个字符   | [cb]at   | act, bat          |
| [a-z]  | 匹配括号中字符范围中的单个字符 | [a-z]at  | aat, bat, zat     |

.gitignore 文件的格式规范：
1. 所有空行或以 # 开头的行都会被忽略
2. 可以使用标准的 glob 模式匹配
3. 匹配模式加 / 代表目录
4. ! 代表取反
```gitignore
#注释
.a         #忽略所有 .a 结尾的文件
!lib.a     #不忽略 lib.a 文件
/TODO      #忽略根目录下的 TODO 文件
build/     #忽略 build 目录下的所有文件
doc/*.txt  #忽略 doc 目录下以 txt 结尾的文件
```

#### 2.3.5 查看文件内容差异

git diff 查看工作目录下与暂存区文件内容的差异。
git diff --staged 查看暂存区与上次提交的文件内容差异。
```dos
diff --git a/1.txt b/1.txt
index bea3e9c..fa34aff 100644
--- a/1.txt
+++ b/1.txt
@@ -1 +1 @@
-1111111111111111111
+updateupdateupdate
```

##### 2.3.6 提交更新

git commit

#### 2.3.7 跳过使用暂存区

在提交时使用 -a 选项，Git 会把所有已跟踪的文件直接提交，跳过 git add 将文件添加到暂存区的操作。
git commit -a

#### 2.3.8 移除文件

若手动删除工作目录下已追踪文件后，git rm filename 将删除操作保存在暂存区，最后提交删除。
若不手动删除，带上 -r 强制删除。
git rm -f filename 删除暂存区中的文件，工作目录中的文件也一并删除
git rm --staged filename 删除暂存区中的文件，但仍保留在工作目录中

#### 2.3.9 移动文件

git mv file_from file_to

### 2.4 撤销操作

#### 2.4.1 撤销提交

git commit --amend 修改最后一次的提交，不会增加新的提交。若修改暂存区内容，最后一次提交的内容将被修改后的提交覆盖。

#### 2.4.2 取消已暂存文件

git restore --staged filename 将文件从暂存区移除。

#### 2.4.3 取消已修改文件

git restore filename 取消对工作目录下文件的修改

### 2.5 查看提交历史

git log 查看所有更新，最新的排在上面。每次更新都有一个 SHA-1 校验和、作者姓名和邮箱、提交时间和提交说明。
```
git log
commit 34bb72c15ad5de1f29d0b6797de1eb886d94511c (HEAD -> master)
Author: Andy <AndyCorona@gmail.com>
Date:   Fri Aug 20 12:21:42 2021 +0800

    third commit

commit a27416aaba5431247a5fad67fb0b425b80b5be0b
Author: Andy <AndyCorona@gmail.com>
Date:   Fri Aug 20 12:18:58 2021 +0800

    second commit

commit 0bad79a1176c6abc3a2b926cef09ef9726e01c61
Author: Andy <AndyCorona@gmail.com>
Date:   Fri Aug 20 08:55:20 2021 +0800

    first commit
```
-p 选项按补丁格式显示每次提交的内容差异
-n 显示最近的 n 次更新
--since，--after=“date” 显示指定时间之后的提交
--until，--before="date" 显示指定时间之前的提交
--author 显示指定作者相关的提交
--committer 显示指定提交者相关的提交
--stat 显示文件修改统计信息
--shortstat 只显示 --stat 中最后的行数修改添加移除统计
--name-only 在提交说明后显示一个已修改的文件清单
--name-status 在提交说明后面显示一个新增、修改和删除的文件清单
--relativ-date 使用较短地相对时间显示
--graph 显示 ASCII 图形表示地分支合并历史
--pretty=[short|full|fuller|format] 使用其他格式显示历史提交信息。

format 可以定义要显示的记录格式，便于后期变成提取分析。

| 选项 | 说明                             |
| ---- | -------------------------------- |
| %H   | 提交对象的完整哈希字符串         |
| %h   | 提交对象的简短哈希字符串         |
| %T   | 树对象的完整哈希字符串           |
| %t   | 树对象的简短哈希字符串           |
| %P   | 父对象的完整哈希字符串           |
| %p   | 父对象的简短哈希字符串           |
| %an  | 作者的名字                       |
| %ae  | 作者的电子邮件地址               |
| %ad  | 作者的修订日期（以绝对时间表示） |
| %ar  | 作者的修订日期（以相对时间表示） |
| %cn  | 提交者的名字                     |
| %ce  | 提交者的电子邮件地址             |
| %cd  | 提交日期（以绝对时间表示）       |
| %cr  | 提交日期（以相对时间表示）       |
| %s   | 提交说明                         |

```dos
#显示作者姓名邮箱以及提交信息，筛选条件为作者为 Andy，3 周之内的提交
git log --pretty=format:"%an - %ae :%s" --author=Andy --since="3 weeks"
Andy - AndyCorona@gmail.com:third commir
Andy - AndyCorona@gmail.com::second commit
Andy - AndyCorona@gmail.com:first commit
```
### 2.6 使用远程仓库
远程仓库是指托管在网络上的项目仓库，可能有好多个。

#### 2.6.1 查看远程仓库

git remote

```dos
git remote -v 查看所有远程仓库
origin  git@github.com:AndyCorona/OnlineCity.git (fetch)
origin  git@github.com:AndyCorona/OnlineCity.git (push)

git remote add ol git@github.com:AndyCorona/OnlineCity.git # 手动添加远程仓库，仓库名为 ol

git remote show ol #查看详细的远程仓库信息
* remote ol
  Fetch URL: git@github.com:AndyCorona/OnlineCity.git
  Push  URL: git@github.com:AndyCorona/OnlineCity.git
  HEAD branch: master
  Remote branches:
    dev    new (next fetch will store in remotes/ol)
    master tracked
  Local ref configured for 'git push':
    master pushes to master (up to date)

```
#### 2.6.2 拉取与抓取

git fetch 仓库名
git pull 仓库名
```dos
git fetch ol #抓取上一次抓取后远程仓库更新的内容。将新内容下载到本地仓库，不会自动合并
git pull ol #若当前分支设置了跟踪远程分支，pull 会自动拉取新内容并合并到当前分支 
```
#### 2.6.3 推送

git push 远程仓库名 分支名

```dos
git push ol master #将 master 分支推送到 ol 远程仓库
git push ol master:mas #将 master 分支推送到 ol 远程仓库的 mas 分支上
```

#### 2.6.4 重命名与移除
```dos
git remote rename ol online # 仓库名 ol 重命名为 online
git remote remove ol #删除远程库 ol
```


### 2.7 打标签
发布某个版本软件时，经常打上一个标签。Git 有两种标签：轻量级和含附注的。轻量级标签是指向特定提交对象的引用，不会变化。含附注的标签是独立储存在仓库中的一个对象，它有自身的检验和信息，包含着标签的名字，邮箱和日期。一般建议使用含附注的标签，临时加注使用轻量级标签。

#### 2.7.1 列出已有标签

git tag 显示所有已有标签
git tag -l "v1.4.2.\*" 显示所有 v1.4.2.x 系列的标签
```dos
git tag
v1.4
v1.4-1w
```

#### 2.7.2 创建标签

git tag tagname 创建轻量级标签
git tag -a tagname -m message 创建含附注的标签
加上提交对象的校验和可以补加标签。

```dos
git tag v1.4-1w 创建轻量级标签 v1.4-1w
git tag -a v1.4 -m "version1.4" 创建含附注的标签 v1.4，version1.4 为说明信息
```

#### 2.7.3 显示标签具体信息

git show tagname 显示含附注标签及其提交对象的信息
```dos
git show v1.4
tag v1.4 #含附注标签信息
Tagger: Andy <AndyCorona@gmail.com>
Date:   Tue Aug 24 08:37:55 2021 +0800

version1.4

commit f4d91a3697a7d049a820bae16ecb82db8201197b (HEAD -> master, tag: v1.4-1w, tag: v1.4) #提交对象信息
Author: Andy <AndyCorona@gmail.com>
Date:   Tue Aug 24 08:37:36 2021 +0800

    first commit

diff --git a/1.txt b/1.txt
new file mode 100644
index 0000000..e69de29
diff --git a/2.txt b/2.txt
new file mode 100644
index 0000000..e69de29
```
轻量级标签保存其提交对象的检验和信息，没有独立的标签信息。所有 git show 显示其提交对象信息。
```dos
git show v1.4-1w
commit f4d91a3697a7d049a820bae16ecb82db8201197b (HEAD -> master, tag: v1.4-1w, tag: v1.4)
Author: Andy <AndyCorona@gmail.com>
Date:   Tue Aug 24 08:37:36 2021 +0800

    first commit

diff --git a/1.txt b/1.txt
new file mode 100644
index 0000000..e69de29
diff --git a/2.txt b/2.txt
new file mode 100644
index 0000000..e69de29
```

#### 2.7.4 签署与验证标签
含附注的标签可以使用 GNU Privacy Guard (GPG) 来签署或验证
-s 签署密钥，-v 验证密钥

git tag -s v1.4 -m "signed version1.4.1" 
git tag -v v1.4.1

#### 2.7.5 分享标签
默认情况下，git push 不会把本地标签传到远程仓库，只有显式命令才能分享标签。
git push xxx [tagname] 分享指定本地标签
git push xxx --tags 分享所有本地标签

### 2.8 小技巧

#### 2.8.1 自动补全

#### 2.8.2 命令别名