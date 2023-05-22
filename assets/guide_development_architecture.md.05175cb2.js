import{_ as e,c as a,o as t,O as i}from"./chunks/framework.389d77d5.js";const o="/university-hangman/assets/06-architecture-windows.08bd07c0.png",r="/university-hangman/assets/07-architecture-windows-changing.a30ab240.png",f=JSON.parse('{"title":"Архітектура","description":"","frontmatter":{},"headers":[],"relativePath":"guide/development/architecture.md"}'),n={name:"guide/development/architecture.md"},c=i('<h1 id="архітектура" tabindex="-1">Архітектура <a class="header-anchor" href="#архітектура" aria-label="Permalink to &quot;Архітектура&quot;">​</a></h1><h2 id="система-вікон" tabindex="-1">Система вікон <a class="header-anchor" href="#система-вікон" aria-label="Permalink to &quot;Система вікон&quot;">​</a></h2><p>Програма розбита на так звані вікна. Це Qt віджети, які містять у собі який-небудь контент, наприклад вікно з приведенням, вікно з грою, вікно з виведенням інформації про програму тощо. Ці вікна контролюються в корені Qt віджета, таких як <code>MainWindow</code>.</p><p>На зображенні демонструється загальний вигляд цих вікон:</p><ul><li>Є головне MainWindow.</li><li>MainWindow відтворює один із доступних віджетів.</li></ul><p><img src="'+o+'" alt="Arch"></p><p>Оскільки нам необхідно змінювати вікна за якихось дій користувача, віджети надсилатимуть сигнали, а <code>MainWindow</code> їх оброблятиме. Так, ми можемо логічно переходити на інші вікна, прив&#39;язуючи сигнали дочірніх віджетів до зміни вікон.</p><p>Виглядає це приблизно так:</p><p><img src="'+r+'" alt="Arch"></p><h2 id="ігровии-контролер" tabindex="-1">Ігровий контролер <a class="header-anchor" href="#ігровии-контролер" aria-label="Permalink to &quot;Ігровий контролер&quot;">​</a></h2><p>Віджети розв&#39;язують проблему з поділом коду на рівні UI, але два різні віджети можуть вимагати одні й ті самі дані або ж змінювати стан гри, впливаючи на інші віджети. Для того, щоб спростити код між віджетами, ми використовуємо ігровий контролер <code>GameController</code>, який доступний глобально.</p><p>Він керує поточним станом гри і містить у собі прогрес самої гри, якщо її розпочато.</p>',12),s=[c];function d(p,l,_,h,u,m){return t(),a("div",null,s)}const b=e(n,[["render",d]]);export{f as __pageData,b as default};
