# Ведення гілок

Git – це розподілена система управління версіями, яка дозволяє розробникам працювати над проектами спільно та ефективно. Одним із ключових аспектів Git є гілки, які дозволяють розробляти та тестувати нові функції незалежно від основного коду.

## Гілки

Для даного проекту буде наступне налаштування розгалужень git

- **main** - головна продакшен гілка, що містить релізні версії продукту.

- **develop** – гілка для розробки, яка містить код для розробки продукту

- **hotfix** - гілка для виправлення помилок та багів

## Правила

1. Будь-який коміт повинен містити працездатний код, який може збиратися без помилок.

2. Будь-який змінений файл, перед тим, як буде додано до комміту, обов'язково повинен бути відформатованим.

3. Злиття develop гілки з main може бути тільки в кінці скрам ітерації і тільки тим лідом.

4. Гілка hotfix використовується лише для виправлення знайдених багів. Розробник переключається на гілку, виправляє знайдених баг, робить пуш гілки репозиторій. Потім тих лід робить злиття.
