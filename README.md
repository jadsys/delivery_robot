delivery_robot
=======

概要
=======
このパッケージは弊社[Delivery Robot Node 2](https://github.com/jadsys/DeliveryRobotNode2/tree/main/src/delivery_robot)の改良版になります。
基本的な機能は変わりませんが、下記の点で機能が追加されております。
・RDRからの地図取得機能（起動時、ナビゲーション開始時）
・物体認識カメラシステムにより認識されたロボットの位置取得機能（起動時）

インストール方法
=======
### 1．ROSワークスペースのディレクトリに移動し、リポジトリをクローン
```bash 
cd ~/{ROSワークスペースディレクトリ}/src/
git clone -b "2023年度成果物" https://github.com/jadsys/delivery_robot.git
```
### 2．Buildを行う
```bash 
cd delivery_robot
catkin build --this
```
### X. 依存関係の解決
当パッケージでは外部パッケージとして以下を利用しております。
- [uoa_poc3_msgs](https://github.com/jadsys/uoa_poc3_msgs.git)
- [uoa_poc5_msgs](https://github.com/jadsys/uoa_poc5_msgs.git)
- [uoa_poc6_msgs](https://github.com/jadsys/uoa_poc6_msgs.git)

それぞれのインストールを行います。
```bash
# vcsツールのインストール（既にインストール済みの場合スキップ）
sudo pip install -U vcstool

# rosdepのインストール
sudo apt install python3-rosdep
sudo rosdep init # 過去に実行済みの場合は実行不要
rosdep update # 過去に実行済みの場合は実行不要

# 依存関係のインストール
cd ~/{ROSワークスペースディレクトリ}/src
vcs import  < delivery_robot/dependency.rosinstall
rosdep install -i --from-paths delivery_robot
catkin build
```

ライセンス
=======
## BSD 3-Clause License

Copyright (c) 2023, Japan Advanced System,Ltd.
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

* Redistributions of source code must retain the above copyright notice, this
  list of conditions and the following disclaimer.

* Redistributions in binary form must reproduce the above copyright notice,
  this list of conditions and the following disclaimer in the documentation
  and/or other materials provided with the distribution.

* Neither the name of the copyright holder nor the names of its contributors 
   may be used to endorse or promote products derived from this software 
   without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

* * *
## 使用ライブラリ関係
### [OpenCV](https://github.com/opencv/opencv)
 [Apache 2.0 License](https://opensource.org/licenses/Apache-2.0)

