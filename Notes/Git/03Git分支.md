# 第三章 Git 分支

### 3.1 何为分支

修改文件添加到暂存区时，暂存操作会为每一个文件计算校验和，用 blob 对象储存当前版本的文件快照。提交之后，Git 会计算每一个子目录的校验和，将项目目录结构保存为一个树对象，树对象指向暂存区的 blob 对象。Git 还会保存一个提交对象，指向树对象，还包含了作者的姓名、邮箱、提交说明和指向父对象的指针。首次提交产生的提交对象没有父对象，后续提交产生的提交对象有一个父对象，多个分支合并产生的提交对象有多个父对象。

![首次提交之后](E:\BaiduNetdiskDownload\Typora\Git\03Git分支.assets\image-20210825081229661.png)
图一、首次提交之后

![多次提交之后](E:\BaiduNetdiskDownload\Typora\Git\03Git分支.assets\image-20210825081303963.png)
图二、多次提交之后


Git 分支，本质上就是指向提交对象的可变指针。Git 默认分支名字为 master。每次提交之后，master 分支会自动向前移动。

![Git分支](E:\BaiduNetdiskDownload\Typora\Git\03Git分支.assets\image-20210825081620610.png)
图三、Git 分支及其提交历史

### 3.2 创建分支

Git 创建新分支，就是创建一个新的可变指针，指向当前提交对象。
git branch testing 创建 testing 新分支
![创建testing分支](E:\BaiduNetdiskDownload\Typora\Git\03Git分支.assets\image-20210825081843297.png)

图四、创建新分支

Git 可以有很多个分支，并用 HEAD 指针表明当前所在分支。git branch 可以查看当前所在分支。
````dos
  master
* testing
````

![HEAD指针](E:\BaiduNetdiskDownload\Typora\Git\03Git分支.assets\image-20210825082048864.png)
图五、HEAD 指针指向当前所在分支

### 3.3 切换分支
git checkout 切换到一个已存在的分支。
```dos
git check testing
Switched to branch 'testing'
git log --pretty=oneline
db6214fcc180093a6135f86c7193547dfc2b200a (HEAD -> testing, master) first commit
```

若再次提交，当前所在 testing 分支会向前移动，HEAD 指针指向当前所在分支，原来的 master 分支不变。

![再次提交](E:\BaiduNetdiskDownload\Typora\Git\03Git分支.assets\image-20210825083400022.png)
图六、切换到 testing 分支
若此时切换回 master 分支，HEAD 指针指向当前所在分支，工作目录下的文件恢复为 master 分支的版本。

![恢复分支](E:\BaiduNetdiskDownload\Typora\Git\03Git分支.assets\image-20210825083545113.png)
图七、切换到 master 分支

Git 分支本质上是包含所指对象校验和的文件，创建一个新分支相当于往一个文件中写入41个字节（40 个 SHA-1 字符串和 1 个换行符），所以创建和销毁分支异常高效。而过去大多数版本控制系统创建分支需要复制整个项目文件，花费时间长。

### 3.4 合并分支
在切换分支之前，留意工作目录和暂存区里未提交的修改，确保所有的修改都已经提交，再切换分支。切换分支后，Git 会自动添加、删除、修改文件以确保工作目录和当前所在分支最后一次提交的样子一模一样
git checkout -b iss53 创建并切换到 iss53 分支。创建完 iss53 分支进行新的开发，并提交了一次。

![新分支](E:\BaiduNetdiskDownload\Typora\Git\03Git分支.assets\image-20210825084830814.png)

图八、创建并切换到 iss53 分支，提交一次

在 iss53 分支上进行开发时，master 分支突然出现问题，我们可以先放下 iss53 分支的工作，切换到 master 分支，创建 hotfix 分支用于热修复，修复完毕后提交。

![新分支](E:\BaiduNetdiskDownload\Typora\Git\03Git分支.assets\image-20210825084851569.png)

图九、创建并切换到 hotfix 分支，提交一次修复

此时切换回 master 分支，将 hotfix 分支合并到 master 分支中。git merge 合并指定分支。

```dos
git checkout master
git merge hotfix
Updating d0a2718..282ceed
Fast-forward
 2.txt | 2 +-
 1 file changed, 1 insertion(+), 1 deletion(-)
```
在合并时，出现 Fast-forward 提示。当试图合并两个分支时，如果顺着一个分支往前走能达到另一个分支（master 往前走能达到 hotfix 分支），这种没有分歧的合并叫做快进（Fast-forward）。合并后，master 分支和 hotfix 分支指向同一个提交对象。

![快进合并](E:\BaiduNetdiskDownload\Typora\Git\03Git分支.assets\image-20210826084637900.png)

应该及时删除临时分支 hotfix，用 git branch -d 删除指定分支。
```dos
git branch -d hotfix
Deleted branch hotfix (was 282ceed).
```
解决完临时问题后，在 iss53 分支上又进行了一些开发，并最终完成。此时需要合并 master 分支和 iss53 分支。
![继续工作](E:\BaiduNetdiskDownload\Typora\Git\03Git分支.assets\image-20210826085440439.png)

此时的合并不同于之前的快进合并， master 分支不能通过向前移到达 iss53 分支，Git 采用三方合并，使用两个分支和它们的共同祖先进行简单的合并。最终得到新的 master 分支，此分支指向两个提交对象。
```dos
git checkout master
git merge iss53
Merge made by the 'recursive' strategy.
 1.txt | 1 +
 1 file changed, 1 insertion(+)
```


![合并分支](E:\BaiduNetdiskDownload\Typora\Git\03Git分支.assets\image-20210826085735464.png)

![没有分歧的合并](E:\BaiduNetdiskDownload\Typora\Git\03Git分支.assets\image-20210826091019059.png)

有时合并操作不会如此顺利，如果两个不同分支，对同一个文件的同一部分进行了不同的修改，Git 没有办法决定如何处理，此时合并会产生冲突。Git 会等待我们去解决合并产生的冲突。
```dos
git merge iss53
Auto-merging 1.txt
CONFLICT (content): Merge conflict in 1.txt
Automatic merge failed; fix conflicts and then commit the result.
```
git status 查看那些因合并冲突而处于未合并状态的文件。Unmerged paths 显示未合并的冲突文件。
```dos
git status
On branch master
You have unmerged paths.
  (fix conflicts and run "git commit")
  (use "git merge --abort" to abort the merge)

Unmerged paths:
  (use "git add <file>..." to mark resolution)
        both modified:   1.txt

no changes added to commit (use "git add" and/or "git commit -a")
```
Git 会在有冲突的文件中加入标准的冲突解决标记（<<<<<<<, =======, >>>>>>>），手动打开冲突文件解决冲突。
```txt
11111
<<<<<<< HEAD #表示 HEAD 指向的版本（这里就是 master 分支）
hotfix fix here
======= #不同版本分界线
iss53 fix here
>>>>>>> iss53 #表示 iss53 分支
```
解决冲突的方法是只留一个分支的修改，或改成其他内容。记得删除冲突解决标。
```txt
11111
iss53 fix here #保留 iss53 分支的修改
```
解决所有文件冲突后，git add 将其标记为冲突已解决，然后提交。

### 3.5 分支开发工作流

#### 3.5.1 长期分支
只在一个分支上保留完全稳定的代码，还有一些其他分支用来做后续开发。等到稳定后，将开发分支合并到稳定的主分支上。

#### 3.5.2 主题分支
有许多个开发分支，最后将挑选后的开发分支合并成主分支。

### 3.6 远程分支

通常以”远程仓库名/分支名”的形式命名远程分支。从远程服务器克隆时，Git 自动命名仓库名为 origin，拉取它的所有数据，创建一个指向它的 master 分支的指针，并在本地命名为 origin/master。Git 同时会创建一个名为 master 的本地分支。
![克隆](E:\BaiduNetdiskDownload\Typora\Git\03Git分支.assets\image-20210830221700342.png)
本地分支提交几次，远程服务器也更新了几次。此时本地分支和远程仓库出现不同。只要不从远程仓库拉取数据，origin/master 指针就不会移动。
![离线](E:\BaiduNetdiskDownload\Typora\Git\03Git分支.assets\image-20210830221937237.png)
若要与远程服务器同步，运行 fetch 或 pull 更新内容，origin/master 移动到更新后的位置。
![更新](E:\BaiduNetdiskDownload\Typora\Git\03Git分支.assets\image-20210830223551362.png)

#### 3.6.1 跟踪分支

跟踪分支是和远程分支有直接关系的本地分支。如果在一个跟踪分支上输入 git pull，Git 能自动识别去哪个服务器抓取并合并到哪个分支。
当克隆一个仓库时，会自动创建一个跟踪 origin/master 的 master 分支。
git checkout -b 跟踪分支 远程分支 或 --track
```dos
git checkout -b ms origin/master #创建跟踪分支 ms
git checkout --track origin/master #创建跟踪分支 ms
git branch -u origin/master #设置当前分支为跟踪分支，跟踪 origin/master 远程分支
git branch -vv #查看所有跟踪分支的信息
git fetch --all; git branch -vv #先抓取所有远程仓库，再查看所有跟踪分支的最新信息
```

### 3.7 变基

在 Git 中合并不同分支的修改主要有两种方法：merge 和 rebase。

#### 3.7.1 变基基本操作

变基和合并最后的结果都一样。合并把两个分支的最新快照和二者最近的共同祖先进行三方合并。

![三方合并](E:\BaiduNetdiskDownload\Typora\Git\03Git分支.assets\image-20210830231520610.png)

还有一种办法是提取一个分支中的补丁和修改，应用在另一个分支上，这种操作叫做变基。
```dos
git checkout experiment #切换到 experment 分支
git rebase master #变基到 master 分支
```
![变基](E:\BaiduNetdiskDownload\Typora\Git\03Git分支.assets\image-20210830231545530.png)
```dos
git checkout master
git merge experiment
```
![变基合并](E:\BaiduNetdiskDownload\Typora\Git\03Git分支.assets\image-20210830231612998.png)
变基使得提交历史更加整洁。对于尚未推送给别人的本地修改执行变基操作清理历史，从不对已推送到别处的提交执行变基操作。