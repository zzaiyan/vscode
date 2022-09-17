# 配置 SSH 密钥实现免密码远程登录
## 第 1 步 — 在本地创建 SSH 密钥

为服务器配置 SSH 密钥身份验证的第一步是在本地计算机上生成 SSH 密钥对。

为此，我们可以使用一个名为 `ssh-keygen` 的特殊实用程序，它包含在标准 OpenSSH 工具套件中。默认情况下，这将创建一个 3072 位的 RSA 密钥对。

在本地计算机上，通过键入以下命令生成 SSH 密钥对：

```
ssh-keygen
Generating public/private rsa key pair.
Enter file in which to save the key (/home/username/.ssh/id_rsa):
```

该实用程序将提示你选择要生成的密钥的位置。默认情况下，密钥将存储在~/.ssh用户主目录中的目录中。将调用私钥并调用 `id_rsa` 关联的公钥 `id_rsa.pub`。

通常，最好在此阶段坚持使用默认位置。这样做将允许你的 SSH 客户端在尝试进行身份验证时自动找到你的 SSH 密钥。如果你想选择非标准路径，请立即输入，否则，请按ENTER接受默认值。

如果你之前生成了 SSH 密钥对，你可能会看到如下提示：
```
/home/username/.ssh/id_rsa already exists.
Overwrite (y/n)?
```

如果你选择覆盖磁盘上的密钥，你将无法再使用以前的密钥进行身份验证。选择“是”时要非常小心，因为这是一个无法逆转的破坏性过程。
```
Created directory '/home/username/.ssh'.
Enter passphrase (empty for no passphrase):
Enter same passphrase again:
```
接下来，系统将提示你输入密钥的密码。这是一个可选密码，可用于加密磁盘上的私钥文件。

密码是可选的添加。这里我们选择不使用密码，按ENTER绕过此提示。
```
Your identification has been saved in /home/username/.ssh/id_rsa.
Your public key has been saved in /home/username/.ssh/id_rsa.pub.
The key fingerprint is:
SHA256:CAjsV9M/tt5skazroTc1ZRGCBz+kGtYUIPhRvvZJYBs username@hostname
The key's randomart image is:
+---[RSA 3072]----+
|o   ..oo.++o ..  |
| o o +o.o.+...   |
|. . + oE.o.o  .  |
| . . oo.B+  .o   |
|  .   .=S.+ +    |
|      . o..*     |
|        .+= o    |
|        .=.+     |
|       .oo+      |
+----[SHA256]-----+
```
你现在拥有一个可用于身份验证的公钥和私钥。下一步是将公钥放置在你的服务器上，以便你可以使用 SSH 密钥身份验证登录。

## 第 2 步 — 将 SSH 公钥复制到你的服务器

有多种方法可以将你的公钥上传到远程 SSH 服务器。你使用的方法很大程度上取决于你可用的工具和当前配置的详细信息。

以下方法都产生相同的最终结果。首先描述最简单、最自动化的方法，随后的方法都需要额外的手动步骤。仅当你无法使用上述方法时，才应遵循这些方法。

### 使用 `ssh-copy-id` 复制你的公钥 

将公钥复制到现有服务器的最简单方法是使用名为ssh-copy-id. 由于其简单性，如果可用，建议使用此方法。

该 `ssh-copy-id` 工具包含在许多发行版的 OpenSSH 包中，因此你可能已经在本地系统上使用它。要使此方法起作用，你当前必须具有对服务器的基于密码的 SSH 访问权限。

要使用该实用程序，你需要指定要连接的远程主机，以及你具有基于密码的 SSH 访问权限的用户帐户。这是你的公共 SSH 密钥将被复制到的帐户。

语法是：

```
ssh-copy-id username@remote_host
```

你可能会看到这样的消息：
```
The authenticity of host '203.0.113.1 (203.0.113.1)' can't be established.
ECDSA key fingerprint is fd:fd:d4:f9:77:fe:73:84:e1:55:00:ad:d6:6d:22:fe.
Are you sure you want to continue connecting (yes/no)? yes
```
这意味着你的本地计算机无法识别远程主机。这将在你第一次连接到新主机时发生。键入`yes`并按ENTER以继续。

接下来，该实用程序将扫描你的本地帐户以查找id_rsa.pub我们之前创建的密钥。当它找到密钥时，它会提示你输入远程用户帐户的密码：
```
/usr/bin/ssh-copy-id: INFO: attempting to log in with the new key(s), to filter out any that are already installed
/usr/bin/ssh-copy-id: INFO: 1 key(s) remain to be installed -- if you are prompted now it is to install the new keys
username@203.0.113.1's password:
```
输入密码（出于安全考虑，你的输入将不会显示）并按ENTER。该实用程序将使用你提供的密码连接到远程主机上的帐户。然后，它会将你的密钥内容复制`~/.ssh/id_rsa.pub`到远程帐户主`~/.ssh`目录中名为`authorized_keys`.

你将看到如下所示的输出：
```
Number of key(s) added: 1

Now try logging into the machine, with:   "ssh 'username@203.0.113.1'"
and check to make sure that only the key(s) you wanted were added.
```
此时，你的 `id_rsa.pub` 密钥已上传到远程帐户。你可以继续下一节。

### 手动复制你的公钥
如果你没有可用的基于密码的 SSH 访问服务器，则必须手动执行上述过程。

你的 `id_rsa.pub` 文件内容必须以 `~/.ssh/authorized_keys` 某种方式添加到远程计算机上的文件中。

要显示id_rsa.pub密钥的内容，请在本地计算机中键入：
```
cat ~/.ssh/id_rsa.pub
```
你将看到密钥的内容，可能如下所示：
```
~/.ssh/id_rsa.pub
ssh-rsa AAAAB3NzaC1yc2EAAAADAQABAAACAQCqql6MzstZYh1TmWWv11q5O3pISj2ZFl9HgH1JLknLLx44+tXfJ7mIrKNxOOwxIxvcBF8PXSYvobFYEZjGIVCEAjrUzLiIxbyCoxVyle7Q+bqgZ8SeeM8wzytsY+dVGcBxF6N4JS+zVk5eMcV385gG3Y6ON3EG112n6d+SMXY0OEBIcO6x+PnUSGHrSgpBgX7Ks1r7xqFa7heJLLt2wWwkARptX7udSq05paBhcpB0pHtA1Rfz3K2B+ZVIpSDfki9UVKzT8JUmwW6NNzSgxUfQHGwnW7kj4jp4AT0VZk3ADw497M2G/12N0PPB5CnhHf7ovgy6nL1ikrygTKRFmNZISvAcywB9GVqNAVE+ZHDSCuURNsAInVzgYo9xgJDW8wUw2o8U77+xiFxgI5QSZX3Iq7YLMgeksaO4rBJEa54k8m5wEiEE1nUhLuJ0X/vh2xPff6SQ1BL/zkOhvJCACK6Vb15mDOeCSq54Cr7kvS46itMosi/uS66+PujOO+xt/2FWYepz6ZlN70bRly57Q06J+ZJoc9FfBCbCyYH7U/ASsmY095ywPsBo1XQ9PqhnN1/YOorJ068foQDNVpm146mUpILVxmq41Cj55YKHEazXGsdBIbXWhcrRf4G2fJLRcGUr9q8/lERo9oxRm5JFX6TCmj6kmiFqv+Ow9gI0x8GvaQ== username@hostname
```
使用你可用的任何方法访问你的远程主机。这可能是你的基础设施提供商提供的基于 Web 的控制台。
```
mkdir -p ~/.ssh
```
现在，你可以在此目录中创建或修改`authorized_keys`文件。你可以将文件的内容添加到id_rsa.pub文件的末尾，`authorized_keys`并在必要时创建它，使用以下命令：
```
echo public_key_string >> ~/.ssh/authorized_keys
```
在上述命令中，将 `public_key_string` 替换为你在本地系统上执行 `cat ~/.ssh/id_rsa.pub` 命令的输出。它应该以 `ssh-rsa AAAA...` 或类似开头。

## 第 3 步 - 连接远程主机

在本地终端中键入以下命令：
```
ssh username@remote_host
```
不出意外，你已顺利实现了免密码登录远程主机。

## Enjoying It !