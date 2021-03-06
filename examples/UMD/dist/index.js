function processFile(event) {
  var outputTextArea = document.querySelector("textarea");
  outputTextArea.textContent = "Loading...";

  var dataTransfer = event.dataTransfer;
  var files = event.target.files || dataTransfer.files;

  return itk.readImageFile(null, files[0]).then(function({ image, webWorker }) {
    webWorker.terminate();

    function replacer(key, value) {
      if (!!value && value.byteLength !== undefined) {
        return String(value.slice(0, 6)) + "...";
      }
      return value;
    }
    outputTextArea.textContent = JSON.stringify(image, replacer, 4);
  });
}
