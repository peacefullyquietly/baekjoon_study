# SPDX-License-Identifier: AGPL-3.0-or-later
# NOTICE: This code is restricted from being used for any AI or machine learning training purposes.
# SPDX-License-Identifier: AGPL-3.0-or-later
from pathlib import Path
from typing import Set, Dict

SUPPORTED_EXTENSIONS: Set[str] = {'py', 'js', 'rs', 'cpp', 'c', 'java', 'asm'}

COMMENT_STYLES: Dict[str, str] = {
    'py': '# SPDX-License-Identifier: AGPL-3.0-or-later\n# NOTICE: This code is restricted from being used for any AI or machine learning training purposes.\n',
    'js': '// SPDX-License-Identifier: AGPL-3.0-or-later\n// NOTICE: This code is restricted from being used for any AI or machine learning training purposes.\n',
    'rs': '// SPDX-License-Identifier: AGPL-3.0-or-later\n// NOTICE: This code is restricted from being used for any AI or machine learning training purposes.\n',
    'cpp': '// SPDX-License-Identifier: AGPL-3.0-or-later\n// NOTICE: This code is restricted from being used for any AI or machine learning training purposes.\n',
    'c': '// SPDX-License-Identifier: AGPL-3.0-or-later\n// NOTICE: This code is restricted from being used for any AI or machine learning training purposes.\n',
    'java': '// SPDX-License-Identifier: AGPL-3.0-or-later\n// NOTICE: This code is restricted from being used for any AI or machine learning training purposes.\n',
    'asm': '; SPDX-License-Identifier: AGPL-3.0-or-later\n; NOTICE: This code is restricted from being used for any AI or machine learning training purposes.\n'
}

def get_license_header(extension: str) -> str:
    """Retrieve license header for a given file extension."""
    return COMMENT_STYLES.get(extension, '')

def process_file(file_path: Path) -> bool:
    """Process a single file to add license header."""
    try:
        if (ext := file_path.suffix.lstrip('.')) not in SUPPORTED_EXTENSIONS:
            return False

        header = get_license_header(ext)
        if not header:
            return False

        content = file_path.read_text(encoding='utf-8')

        if content.lstrip().startswith(header.strip()):
            return False

        file_path.write_text(header + content, encoding='utf-8')
        return True

    except Exception as e:
        print(f"Error processing {file_path}: {e}")
        return False

def add_headers(root_dir: Path = Path('.')):
    for file_path in root_dir.rglob('*'):
        if file_path.is_file():
            process_file(file_path)

def main():
    add_headers()

if __name__ == '__main__':
    main()
