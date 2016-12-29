# TinyHSP

TinyHSPは**クリーンなHSPを作成する**ことを目標にしたプロジェクトです。

## TinyHSPで作るもの

プラットフォーム共通の**TinyHSPコンパイラとエンジン**を作成します。また**各OSごとにランタイム**を作成します。

## TinyHSPの仕様

本家HSPの仕様をコンパクトにしたものになっています。対応する命令については[TinyHSPの命令・関数の仕様](https://github.com/dolphilia/tinyhsp/wiki/TinyHSPの命令・関数の仕様)を参照してください。

## TinyHSPの始まり

HSPの公式サイトの掲示板に投稿された[TinyHSPの提案](http://hsp.tv/play/pforum.php?mode=all&num=77515)がきっかけです。

## どんなことでもissuesにどうぞ

Githubでは掲示板のスレッドのような機能「イシュー」を使うことができます。質問や提案がありましたら、ご自由に[Issuesのページ](https://github.com/dolphilia/tinyhsp/issues)からイシューを立てていただければと思います。

※ 注意すべき点として、イシューは削除することができません。イシューを立てる際には内容をよく吟味するようお勧めします。

## コミッターさん向けのガイド

このプロジェクトは__楽しんで開発しよう__という基本方針で動いています。コミッター向けのルールは次のようなものです。

1. 開発すること自体を楽しむ
2. ボトムアップ方式で１から作る
3. コア部分はC言語で実装する
4. 非コア部分は各OSで推奨される方法で実装する
5. コミットメッセージには「なぜこうしたか」を書く
6. HSPの命令・構文ともに拡張しないようにする
7. 実装する命令は[TinyHSPの命令・関数の仕様](https://github.com/dolphilia/tinyhsp/wiki/TinyHSPの命令・関数の仕様)を参照する

詳しくはWikiのページ[プロジェクトのルール](https://github.com/dolphilia/tinyhsp/wiki/プロジェクトのルール)をご覧ください。

## Q & A

Wikiのページ[Q & A](https://github.com/dolphilia/tinyhsp/wiki/Q-&-A)をご覧ください。

## ライセンス

TinyHSPはMITライセンスです。
