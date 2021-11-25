# リポジトリ構造

このGithubリポジトリでは,プロジェクトベースでフォルダを作成し,その中に MechanicalBody(筐体),Circuit(回路),Firmware(組み込みソフト),アプリケーション(アプリケーション) フォルダを作成し、その中に各開発環境のプロジェクトを作成しています.

```
Repository

    /Project1
        Readme.md #Project1の概要説明

        /MechanicalBody
            /EMGArmBand/Readme.md #EMGArmBandの概要説明,ビルド環境,利用の仕方など
            /EMGArmBand/Project's files..
            /EMG1ChCircuitCover/Readme.md
            /EMG1ChCircuitCover/Projects's files..

        /Circuit
            /EMG1ChAnalogAmplifier/Readme.md
            /EMG1ChAnalogAmplifier/Project's files..

        /Firmware
            /AnalogAD1Ch/Readme.md
            /AnalogAD1Ch/Project's files..

        /Application
            /Serial1ChMonitor/Readme.md
            /Serial1ChMonitor/Project's files..

    /Project2
    ...

    /Doc # OSSドキュメント用フォルダ

    
```