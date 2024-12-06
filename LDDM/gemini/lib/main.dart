import 'dart:io';

import 'package:flutter/material.dart';
import 'package:image_picker/image_picker.dart';
import 'package:google_generative_ai/google_generative_ai.dart';

void main() async {
  runApp(const MyApp());
}

class MyApp extends StatelessWidget {
  const MyApp({super.key});

  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      title: 'Flutter Demo',
      theme: ThemeData(
        colorScheme: ColorScheme.fromSeed(seedColor: Colors.deepPurple),
        useMaterial3: true,
      ),
      home: const MyHomePage(title: 'Flutter Demo Home Page'),
    );
  }
}

class MyHomePage extends StatefulWidget {
  const MyHomePage({super.key, required this.title});

  final String title;

  @override
  State<MyHomePage> createState() => _MyHomePageState();
}

class _MyHomePageState extends State<MyHomePage> {
  File? _selectedImage;

  // Função para selecionar uma imagem da galeria ou tirar uma foto
  Future<void> _chooseImageSource() async {
    final ImagePicker picker = ImagePicker();

    showModalBottomSheet(
      context: context,
      builder: (BuildContext context) {
        return SafeArea(
          child: Wrap(
            children: <Widget>[
              ListTile(
                leading: const Icon(Icons.photo_library),
                title: const Text('Galeria'),
                onTap: () async {
                  final XFile? image = await picker.pickImage(source: ImageSource.gallery);
                  if (image != null) {
                    setState(() {
                      _selectedImage = File(image.path);
                    });
                  }
                  Navigator.of(context).pop();
                },
              ),
              ListTile(
                leading: const Icon(Icons.camera_alt),
                title: const Text('Câmera'),
                onTap: () async {
                  final XFile? image = await picker.pickImage(source: ImageSource.camera);
                  if (image != null) {
                    setState(() {
                      _selectedImage = File(image.path);
                    });
                  }
                  Navigator.of(context).pop();
                },
              ),
            ],
          ),
        );
      },
    );
  }

  // Função para enviar a imagem para a IA
  Future<void> _sendImageToAI() async {
    if (_selectedImage == null) {
      return;
    }

    final apiKey = 'API_KEY';
    if (apiKey.isEmpty) {
      print('No \$API_KEY environment variable');
      exit(1);
    }

    final model = GenerativeModel(model: 'gemini-1.5-flash', apiKey: apiKey);
    final image = await _selectedImage!.readAsBytes();
    final prompt = TextPart("Transcreva a nota fiscal, listando todos os produtos, seus respectivos preços (separar a parte inteira da decimal por ponto) e a quantidade individual de cada produto, faça separado em ; para ser usado como um split para separar as informações. Separe cada conjunto de informações em uma linha diferente. Caso a quantidade seja um valor decimal, considere o valor inteiro do teto. Siga o seguinte modelo para cada produto: Nome;Quantidade;Preço, apenas respostas sem comentários do GEMINI AI por favor");

    final imageParts = [
      DataPart('image/jpeg', image)
    ];
    final response = await model.generateContent([
      Content.multi([prompt, ...imageParts])
    ]);
    List<String?> produtos = [];
    produtos.add(response.text);

    for (int i = 0; i < produtos.length; i++) {
      debugPrint(produtos[i]);
    }
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        backgroundColor: Theme.of(context).colorScheme.inversePrimary,
        title: Text(widget.title),
      ),
      body: Center(
        child: Column(
          mainAxisAlignment: MainAxisAlignment.center,
          children: <Widget>[
            _selectedImage == null
                ? const Text('Nenhuma imagem selecionada.')
                : Image.file(_selectedImage!),
            const SizedBox(height: 20),
            ElevatedButton(
              onPressed: _chooseImageSource,
              child: const Text('Selecionar/Tirar Foto'),
            ),
            const SizedBox(height: 20),
            ElevatedButton(
              onPressed: _sendImageToAI,
              child: const Text('Enviar Imagem para IA'),
            ),
          ],
        ),
      ),
    );
  }
}
