﻿// -*- mode:c++; coding:utf-8-ws -*-
#ifndef MY_CONFIG_H
#define MY_CONFIG_H

// clang-format off

// 2016.7.28, 2.1.1.4(r3825)ベース
// 2016.7.29, 2.2.0.1(r4011)ベース

// ●やりたいこと.
// - [x] 2015.6.1
//  検索時、選択している文字列があった場合に正規表現にチェックが入っていたら
//  正規表現で使用する記号を自動的にクォートする.
//  PHPの preg_quote みたいなもの.
//
// - [ ] 2015.6.2
//  検索文字列がある行番号の色を変更したい.
//
// - [ ] 2015.6.5
//  bug?, 単語を削除する際、一瞬選択状態になる
//
// - [x] 2015.6.5
//  bug, カーソル移動したときに移動前の状態が一瞬残る
//  \view\CEditView_Scroll.cpp:void CEditView::ScrollDraw() があやしい?
//  ScrollWindowEx() で行われる更新をなんとかすればいい?
//
// - [x] 2015.6.5
//  Grep対象のフォルダの複数指定.
//
// - [ ] 2015.6.8
//  起動時、最近使ったファイルの整理. 存在しないファイルの項目を排除.
//
// - [ ] 2015.6.9
//  ウィンドウ一覧表示,
//     DELでウィンドウを閉じる.
//     選択でウィンドウをアクティブにする.
//
// - [x] 2015.6.10
//  ステータスバーにタイプ名を表示.
//  \window\CMainStatusBar.cpp : CMainStatusBar::CreateStatusBar()
//  \apiwrap\CommonControl.h : ApiWrap::StatusBar_SetParts
//  \window\CEditWnd.cpp : CEditWnd::OnSize2 : nStArr カラムサイズ
//
// - [x] 2015.6.11
//  iniをレジストリによる読み書きにする.
//
// - [ ] 2015.6.30
//  コメント内の検索文字列はコメント色の影響を受ける.
//
// - [ ] 2015.7.2
//  開いているタブのファイル名をコピー.
//
// - [ ] 2015.8.4
//  タスクバーアイコンのちらつき
//  \window\CTabWnd.cpp:CTabWnd::ShowHideWindow()
//  SendMessageTimeout() と TabWnd_ActivateFrameWindow() の関係
//
// - [x] 2015.11.23
//  置換のとき、置換後ボックスに置換前のテキストを入れる
//
// - [ ] 2016.12.13
//  各ダイアログボックスの位置をデスクトップの中央ではなく
//  呼び出し元ウィンドウの中央、または左上に配置する
//   - [x] Grep検索中
//   - [x] 外部コマンド実行ダイアログ
//
// - [x] 2017.1.5
//  bug, 行コメントがある行の空白が検索対象の時、検索色背景が空白タブに反映されない
//  REI_MOD_COMMENT の影響
/**/  
/**/  /**/  /**/  
/*

*/
//
// - [x] 2017.1.10
//  選択中のテキストの装飾は元のテキストを優先する
//
// - [ ] 2017.1.10
//  bug?, 画面上端下端でキャレットが消えたタイミングでスクロールさせるとキャレットが消えたままスクロールする
//
// - [ ] 2017.3.3
//  テキスト描画、右端が欠ける
//  [patchunicode:#588]をあてて目立たなくはしている
//  sakura_core\view\CEditView_Paint.cpp
//  pcFigureManager->GetTextFigure().DrawImp(pInfo, nPosBgn, pInfo->GetPosInLogic() - nPosBgn);
//  [patchunicode:#860]をあてれば解消しそう
//
// - [ ] 2017.4.4
//  BkSpを押したときにタブ入力文字だけしかない場合は逆TABにする

// ● フォント
//   https://support.microsoft.com/ja-jp/kb/74299
//   http://d.hatena.ne.jp/itoasuka/20100104/1262585983
//
// lf.lfHeight = DpiPointsToPixels(-10); // 高DPI対応（ポイント数から算出）

#define REI_REGKEY _T("Software\\sakura_REI")

//-------------------------------------------------------------------------
// デバッグ用
//-------------------------------------------------------------------------

// デバッグ出力 2015.3.24
//#define REI_OUTPUT_DEBUG_STRING


//-------------------------------------------------------------------------
// 編集
//-------------------------------------------------------------------------

//------------------------------------------------------------------
// 水平スクロールの変更
//  - スクロール開始マージンを 1 に変更。画面の端でスクロール開始 2014.5.7
//  - スクロール幅を 16 に設定。一度に大きく移動することで見やすくする (動きはメモ帳参照) 2015.9.2
//------------------------------------------------------------------
#define REI_MOD_HORIZONTAL_SCR (16)

//------------------------------------------------------------------
// タブ入力文字の切り替え(タブ<->空白)を追加
//  - S_ChangeTabWidthマクロ修正, 負の値を渡すとタブ文字の切り替え
//------------------------------------------------------------------
#define REI_MOD_CHANGE_TAB_WIDTH_MACRO


//-------------------------------------------------------------------------
// 表示
//-------------------------------------------------------------------------

//------------------------------------------------------------------
// UIフォントの変更
//  - "ＭＳ Ｐゴシック" -> "MS Shell Dlg"
//  - .rcファイルは置換対応
//------------------------------------------------------------------
#define REI_MOD_UI_FONT

//------------------------------------------------------------------
// タブ名カラーの変更
//------------------------------------------------------------------
#define REI_MOD_TAB_CAPTION_COLOR
  // 変更ドキュメントタブ名カラー
  // (REG/TabCaptionModifiedColor:0x00BBGGRR)
  #define REI_MOD_MODIFIED_TAB_CAPTION_COLOR (0x00d70000)
  // マクロ記録中ドキュメントタブ名カラー
  // (REG/TabCaptionRecMacroColor:0x00BBGGRR)
  #define REI_MOD_RECMACRO_TAB_CAPTION_COLOR (0x000000d8)

//------------------------------------------------------------------
// 行を中央ぞろえにする 2014.3.26 - 2015.7.24
//  - デフォルトでは行は上揃えになっているので行間は下に付加される
//  - キャレットを行間含む高さにする xxx
//------------------------------------------------------------------
#define REI_LINE_CENTERING

//------------------------------------------------------------------
// EOFのみの行に行番号を表示 2017.3.10
//------------------------------------------------------------------
#define REI_MOD_EOFLN_DISP_NR

//------------------------------------------------------------------
// キャレットの変更 2012.10.11
// 0: 変更なし
// 1-10: キャレットサイズ
// 11: 1バイトコードの時は1px、2バイトコードの時は2px
// 12: 半角入力の時は1px、全角入力の時は2px 2015.8.26
// (REG/CaretType:2)
//------------------------------------------------------------------
#define REI_MOD_CARET (2)

//------------------------------------------------------------------
// 半角空白文字を "・" で描画 2013.6.2
//------------------------------------------------------------------
#define REI_MOD_HAN_SPACE

//------------------------------------------------------------------
// タブ文字（矢印）の鏃(>)は表示しない 2015.5.25
//  - 「長い矢印」「短い矢印」→「線」 2016.8.19
//  -> タブ表示の文字指定廃止, 表示は線のみ 2017.3.29
//------------------------------------------------------------------
#define REI_MOD_TAB

//------------------------------------------------------------------
// カーソル行アンダーライン
//  - 左端から 2015.1.30
//------------------------------------------------------------------
#define REI_MOD_CUR_UL

//------------------------------------------------------------------
// 選択領域の色を変更
//  - テキストと背景のブレンド率設定 2015.6.5
//  - 選択時のテキスト属性（太字、下線）に選択領域ではなく現在のテキストを使用する
//  - カラー設定は背景カラーのみ
//------------------------------------------------------------------
#define REI_MOD_SELAREA
  // 選択領域のブレンド率[%] 2015.6.5
  // (REG/SelectAreaBlendPer:0x00000064)
  #define REI_MOD_SELAREA_BLEND_PER (/*Text=*/(0 << 8) | /*Back=*/(100))

//------------------------------------------------------------------
// 空白,TAB,改行のカラーを変更 2015.6.5
//  - 現在のテキスト色と現在の背景色をブレンドする (空白TABのカラー設定は無効化されます) 2015.6.8
//    対象は空白TABなどで、コントロールコードには適用されません
//------------------------------------------------------------------
#define REI_MOD_SP_COLOR
  // 空白,TAB,改行 現在のカラーのブレンド率[%] 2015.6.5
  // (REG/WhiteSpaceBlendPer:0x0000001E)
  #define REI_MOD_SP_BLEND_PER (30)
//						     
						     

//------------------------------------------------------------------
// カラー設定の変更 2016.6.25
//  - カーソル位置縦線 テキストカラーのみ
//  - 折り返し記号 テキストカラーのみ
//------------------------------------------------------------------
#define REI_MOD_COLOR_STRATEGY

//------------------------------------------------------------------
// コメント行の修正 2016.12.27
// 0x01: 改行以降もカラーを有効にする
//------------------------------------------------------------------
#define REI_MOD_COMMENT

//------------------------------------------------------------------
// 折り返し記号表示時に折り返し位置の線を引かない 2016.6.25
// (REG/NoWrapLine:1)
//------------------------------------------------------------------
#define REI_MOD_WRAP_LINE

//------------------------------------------------------------------
// ステータスバーを変更 2015.6.10 - 2017.4.1
//  - タイプ名を表示
//  - タブサイズを表示
//    左ダブルクリックで 2>4>8 のトグル
//    右クリックで入力タブ文字の タブ>空白 のトグル
//  - 左端カラムにパスを表示
//  - 「? 行 ? 桁」→「?:?」に変更
//  - 改行コードに主に使われているシステム名を表記
//------------------------------------------------------------------
#define REI_MOD_STATUSBAR

//-------------------------------------------------------------------------
// 機能
//-------------------------------------------------------------------------

//------------------------------------------------------------------
// プロファイルの読み書きにレジストリを使用可能にする
//  - レジストリキーがない場合はiniファイルから読み込む
// (REG/NoReadProfilesFromRegistry:1) 1にするとレジストリから読み込まなくなります
// (REG/NoWriteProfilesToRegistry:1) 1にするとレジストリに書き込まなくなります
//------------------------------------------------------------------
#define REI_USE_REGISTRY_FOR_PROFILES

//------------------------------------------------------------------
// 開かれているファイルを自己管理する前提で多重オープンの許可 2013.6.19
//  - Shiftを押しながらファイルドロップで多重オープン
//------------------------------------------------------------------
#define REI_MULTIPLE_OPEN_FILES

//------------------------------------------------------------------
// 最大数を変更 2013.10.2, 2016.12.13
// \sakura_core\config\maxdata.h
// (REG/RecentSearchKeyMax:16)
// (REG/RecentReplaceKeyMax:16)
// (REG/RecentGrepFileMax:8)
// (REG/RecentGrepFolderMax:16)
//------------------------------------------------------------------
#define REI_CHG_MAXDATA

//------------------------------------------------------------------
// 正規表現検索の際、検索文字列の正規表現記号をクォートする 2015.6.1
// (REG/RegexpAutoQuote:1)
//------------------------------------------------------------------
#define REI_MOD_SEARCH_KEY_REGEXP_AUTO_QUOTE

//------------------------------------------------------------------
// Grep変更 2015.8.24
//  - Grepするフォルダの指定を UI的に増やす
//    →カンマで区切るより分かれていた方が扱いやすいし、履歴管理もしやすい.
//  - 指定フォルダをすべてチェックをはずすと「現在編集中のファイルから検索」とする
//  - 「現在編集中のファイルから検索」をチェックした時の状態を保持しないようにする
//    →本来の「現在編集中のファイルから検索」を使用すると、
//      影響を受ける他のチェックボックスの状態が変更したまま戻らないのが嫌だから.
//  - ファイル(フィルタ)指定はフォルダのあとに置く (フォルダのほうが変更する機会が多いため)
//  - 検索中のダイアログを中央に置かない（リアルタイム時に見づらい）
//------------------------------------------------------------------
#define REI_MOD_GREP

//------------------------------------------------------------------
// 置換変更 2016.8.4
// (REG/ReplaceTextToText:1)
//  - 置換後文字列に置換前文字列を設定する
//------------------------------------------------------------------
#define REI_MOD_REPLACE

//------------------------------------------------------------------
// フォルダ選択ダイアログを変更 2015.8.25
//  - CLSID_FileOpenDialogを使用する
//    使用するには Vista以降にする必要がある
//      -  WINVER=0x0500;_WIN32_WINNT=0x0500;_WIN32_IE=0x0501
//      -> WINVER=0x0601;_WIN32_WINNT=0x0601;_WIN32_IE=0x0800
// http://eternalwindows.jp/installer/originalinstall/originalinstall02.html
// https://msdn.microsoft.com/ja-jp/library/windows/desktop/ff485843(v=vs.85).aspx
// http://qiita.com/hkuno/items/7b8daa37d9b68e390d7e _WIN32_WINNT
// http://www.02.246.ne.jp/~torutk/cxx/vc/vcpp100.html
//------------------------------------------------------------------
#define REI_MOD_SELECTDIR

//------------------------------------------------------------------
// ダイアログを編集ウィンドウに配置 2017.4.4
//  - アウトライン解析
//  - 外部コマンド実行
//  - 検索
//  - 置換
//  - Grep
//  - Grep置換
//  - 指定行へジャンプ
//  - タグジャンプリスト
//  - ウィンドウ一覧表示
//  - 文字コードの指定
//  - 履歴とお気に入りの管理
//  - 更新通知及び確認
// 53         編集ウィンドウの表示位置、この場合は5分の3の位置に表示
// ||         指定できる値は1-9
// |+-- 分子
// +--- 分母
// (REG/PlaceDialogWindowTop:74)
// (REG/PlaceDialogWindowLeft:21)
//------------------------------------------------------------------
#define REI_MOD_DIALOG_POS
  #define REI_MOD_DIALOG_PLACE_TOP (74)
  #define REI_MOD_DIALOG_PLACE_LEFT (21)

//------------------------------------------------------------------
// タグジャンプ一覧を変更
//  - 表示するカラムの選別と並び替え 2015.8.27
//------------------------------------------------------------------
#define REI_MOD_TAGJUMP

//------------------------------------------------------------------
// アウトライン解析ダイアログの変更 2016.12.14
//  - フォントをメインフォントにする
//  - ドッキング時にウィンドウカラーをテキストに合わせない
// (REG/NoOutlineDockSystemColor:0)
//------------------------------------------------------------------
#define REI_MOD_OUTLINEDLG

//------------------------------------------------------------------
// ウィンドウ一覧ポップアップを変更
//  - 位置を指定可能にする 2017.3.29
//  - 0xffffffff指定でウィンドウの中央に配置 2017.4.7
//    (REG/WinListPopupTop:0xffffffff)
//    (REG/WinListPopupLeft:0xffffffff)
//    (REG/WinListPopupWidth:400)
//------------------------------------------------------------------
#define REI_MOD_WINLIST_POPUP
  #define REI_MOD_WINLIST_POPUP_TOP (0xffffffff)
  #define REI_MOD_WINLIST_POPUP_LEFT (0xffffffff)
  #define REI_MOD_WINLIST_POPUP_WIDTH (400)

//------------------------------------------------------------------
// バージョン情報ダイアログの変更 2017.3.15
//------------------------------------------------------------------
#define REI_MOD_VERDLG

//------------------------------------------------------------------
// ウェイトカーソルを変更 2015.7.9
//  - 一部、正しい位置に修正
//  - 文字列削除時に表示しない（アンドゥのときなど）
//------------------------------------------------------------------
#define REI_MOD_WAITCUESOR

//------------------------------------------------------------------
// SetMainFontを修正
//  - 引数ptを追加、デフォルトを9ポイントにする 2017.3.7
//------------------------------------------------------------------
#define REI_MOD_SET_MAIN_FONT


//-------------------------------------------------------------------------
// 修正
//-------------------------------------------------------------------------

//------------------------------------------------------------------
// 検索ダイアログの「正規表現」が影響を受けないようにする
//  - 検索マーク切り替え時 2015.6.1
//  - インクリメンタルサーチ時 2016.12.14
//------------------------------------------------------------------
#define REI_FIX_SEARCH_KEEP_REGEXP

//------------------------------------------------------------------
// 行番号が非表示でブックマークが表示のときブックマークは線で描画する 2017.1.13
//   -> 大した問題ではないので修正しない 2017.3.28
//------------------------------------------------------------------
#if 0
Index: sakura_core\view\CTextDrawer.cpp
@@ 615
	{
		// 2001.12.03 hor
		/* とりあえずブックマークに縦線 */
-		if(CBookmarkGetter(pCDocLine).IsBookmarked() && !cMarkType.IsDisp() )
+		bool bookmark_line = false;
+		bookmark_line |= CBookmarkGetter(pCDocLine).IsBookmarked() && !cMarkType.IsDisp();
+		bookmark_line |= CBookmarkGetter(pCDocLine).IsBookmarked() && !CTypeSupport(pView,COLORIDX_GYOU).IsDisp();
+		if (bookmark_line)
		{
			gr.PushPen(cColorType.GetTextColor(),2);
			::MoveToEx( gr, 1, y, NULL );
#endif
//- #define REI_FIX_DRAW_BOOKMARK_LINE_NOGYOU

//------------------------------------------------------------------
// ルーラー非表示時は「ルーラーとテキストの隙間」を無視する 2016.12.28
//   -> 大した問題ではないので修正しない 2017.3.28
//------------------------------------------------------------------
#if 0
Index: sakura_core\view\CTextArea.h
@@ 108
		return m_nViewCy;
	}

-	int GetTopYohaku() const
-	{
-		return m_nTopYohaku;
-	}
+	int GetTopYohaku() const;
	void SetTopYohaku(int nPixel)
	{
		m_nTopYohaku=nPixel;

Index: sakura_core\view\CTextArea.cpp
@@ 51
	pDst->SetViewLeftCol			( this->GetViewLeftCol() );		// 表示域の一番左の桁(0開始)
}

+int CTextArea::GetTopYohaku() const
+{
+  if (m_pEditView && m_pEditView->m_pTypeData &&
+      !m_pEditView->m_pTypeData->m_ColorInfoArr[COLORIDX_RULER].m_bDisp) {
+    return 0;
+  } else {
+    return m_nTopYohaku;
+  }
+}
+
//!表示域の再計算
void CTextArea::UpdateViewColRowNums()
{
#endif
//- #define REI_FIX_RULER_HIDE_IGNORE_BOTTOM_SPACE

//------------------------------------------------------------------
// 行番号縦線を行番号の色で描画する 2016.12.21
//   -> 大した問題ではないので修正しない 2017.3.28
//------------------------------------------------------------------
#if 0
Index: sakura_core\view\CTextDrawer.cpp
@@ 596
			rc.top = y;
			rc.right = nLineNumAreaWidth - 1;
			rc.bottom = y + nLineHeight;
-			gr.FillSolidMyRect(rc, fgcolor);
+			gr.FillSolidMyRect(rc, cGyouType.GetTextColor());
		}

		gr.PopTextForeColor();
#endif
//- #define REI_FIX_LINE_TERM_TYPE

//------------------------------------------------------------------
// カーソル上下移動時に次の条件?のときに画面の更新が間に合わずに描画が崩れる 2015.8.4
//  - キーリピートが早い
//  - 裏で描画を頻繁に行うアプリが動いている
// →UpdateWindow() を呼び出すことで一時対応
//------------------------------------------------------------------
#define REI_FIX_CALL_CURSOR_MOVE_UPDATEWINDOW

//------------------------------------------------------------------
// カーソル移動時のちらつきを暫定で対処 2015.8.4
//  - スクロールした時に ScrollWindowEx() と再描画の同期がとれていない?
//  - MacTypeなどを使用すると描画の負荷が高くなり顕著になる。使わない場合は高速にやると再現する
// →MoveCursor()に処理をまとめてしばらく様子見 2015.8.5
//------------------------------------------------------------------
#define REI_FIX_CURSOR_MOVE_FLICKER

//------------------------------------------------------------------
// タブウィンドウの処理を修正 2015.8.28
//  - ウィンドウまとめモードの切り替え時にスリープを10ms入れる(ちらつき抑制) 2017.4.6
//  - タブをダブルクリックで閉じる 2017.4.6 - 2017.4.7
//    (REG/DoubleClickClosesTab:1)
//  ! 各ウィンドウのタブウィンドウは生成時に自身の位置が選択されている状態から始まる
//    オーダーが変わらない限り選択タブが変わることはない
//    ウィンドウ切り替え時に自身が選択されたタブウィンドウが表示されることでタブを切り替えたように表現しているだけ
//    そのためスクロール状態からの切り替え時にスクロール位置が同期していない
//------------------------------------------------------------------
#define REI_FIX_TABWND


//
//#define USE_SSE2

#endif /* MY_CONFIG_H */
